#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"

extern char idd[20], guess[20], password[20]; //教师登陆密码使用
extern FILE * fp;  //文件指针
extern int k, j, quit;  //k控制界面，，j接受输入的选择序号，q 结束程序控制
extern stu *head, *p, *n, *student_pt;

int main(void){
    start(); //学生成绩数据初始化函数
    while(1){
        system("cls");
        switch(k)
        {
        case 0://主界面
            viewa();
            printf("\n请输入前面的序号进行选择：");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("输入不合法，请重新输入：");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:   // 转为学生端
                judge_passwordx(); //学生登陆函数
                break;
            case 1:   //转为教师端
                judge_passwordj(); //教师登陆函数
                break;
            case 2:   //退出程序
                quit = 1;
            }
            break;


        case 1: //学生端
            viewx();
            printf("\n请输入前面的序号进行选择：");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("输入不合法，请重新输入：");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:  //查询考试成绩
                find_scorex(); //成绩查询函数
                break;
            case 1:  //查询平均分,最高分
                find_else();
                break;
            case 2:  //查询排名
                find_range();
                break;
            case 3:  //修改用户名
                change_id();
                break;
            case 4:  //修改密码
                change_passwordx();
                break;
            case 5:  //返回上一界面
                k = 0;
                break;
            case 6:  //退出系统
                quit = 1;
            }
            break;


        case 2:   //教师端
            viewj();
            printf("\n请输入前面的序号进行选择：");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("输入不合法，请重新输入：");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:   // 修改教师登陆密码
                change_passwordj();  //密码修改函数
                break;
            case 1:   //新增学生成绩
                new_score();
                break;
            case 2:   //删除生信息录入
                delete_score();
                break;
            case 3:   //修改学生信息
                change_score();
                break;
            case 4:   //查询学生成绩
                find_scorej();
                break;
            case 5:   //返回主页面
                k = 0;
                break;
            case 6:   //退出程序
                quit = 1;
            }
        }
        if(quit == 1){
            break;
        }
    }
    end_(); //结束函数
}
