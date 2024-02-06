#include "mynetwork.h"

#include "widget.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    int soc = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP));
    QApplication a(argc, argv);
    Widget w;

    new QLabel("hello, qt", &w);

    w.show();
    return a.exec();
}

/*
void* procAnalyzeP(void* param){
    struct anlParam *prm = (anlParam *)param;
    #define LabelstrMax 20
    char labelstr[LabelstrMax];
    char tmpstr[LabelstrMax];
    #undef LabelstrMax
    unsigned char tmpCnt = 0;
    int soc;
    int readPnum;
    u_char buf[32767];
    memset(buf, 0x00, sizeof(buf));
    soc = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP));

    while(1){
        readPnum = read(soc,buf,sizeof(buf));
        if(readPnum > 0){
            AnalyzeIPpacketGTK(buf);

            bufToHexStr(buf, sizeof(buf), tmpstr);

            sprintf(labelstr, "read buf: %s", tmpstr);
            gtk_label_set_text((GtkLabel*)prm->wdg.label1, (const char*)labelstr);
        }else{
            g_print("buf is Null\n");
        }
    sprintf(labelstr, "nowcnt: %d", tmpCnt++);
    gtk_label_set_text((GtkLabel*)prm->wdg.label, (const char*)labelstr);

    }
}*/
