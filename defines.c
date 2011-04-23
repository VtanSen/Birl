#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "defines.h"

//调试信息输出
void debug(const char *fileName,const char *functionName,const char *debugInfo)
{
    printf("Debug\t%s    文件：%s    函数：%s\n",debugInfo,fileName,functionName);
}
void guiDebug(const char *fileName,const char *functionName,const char *debugInfo)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT,             //跟随父窗口关闭
                                    GTK_MESSAGE_INFO,                        //显示图标
                                    GTK_BUTTONS_OK,                             //不显示按钮
                                    "文件：%s\n函数：%s\n信息：%s\n",fileName,functionName,debugInfo);
    GtkWidget *image = gtk_image_new_from_file(ICO_PATH);
    gtk_widget_show(image);
    gtk_message_dialog_set_image (GTK_MESSAGE_DIALOG(dialog), image);
    gtk_window_set_title(GTK_WINDOW(dialog), ("出错信息"));//对话框的标题
    gtk_dialog_run(GTK_DIALOG(dialog));//运行对话框
    gtk_widget_destroy(dialog);//删除对话框
}

void user2net()
{
    strcpy(net.userName,user.userName);
    strcpy(net.passwd,user.passwd);
    strcpy(net.nic,user.nic);
    net.startMode=strcmp(user.startMode,"标准")==0?0:1;
    net.dhcpMode=strcmp(user.dhcpMode,"静态")==0?0:(strcmp(user.dhcpMode,"二次认证")==0?1:(strcmp(user.dhcpMode,"认证后")==0?2:3));
    net.ip=inet_addr(user.ip);
    net.mask=inet_addr(user.mask);
    sprintf(net.dhcpScript,D_DHCPSCRIPT,net.nic);
}


