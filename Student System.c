#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"

extern char idd[20], guess[20], password[20]; //��ʦ��½����ʹ��
extern FILE * fp;  //�ļ�ָ��
extern int k, j, quit;  //k���ƽ��棬��j���������ѡ����ţ�q �����������
extern stu *head, *p, *n, *student_pt;

int main(void){
    start(); //ѧ���ɼ����ݳ�ʼ������
    while(1){
        system("cls");
        switch(k)
        {
        case 0://������
            viewa();
            printf("\n������ǰ�����Ž���ѡ��");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("���벻�Ϸ������������룺");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:   // תΪѧ����
                judge_passwordx(); //ѧ����½����
                break;
            case 1:   //תΪ��ʦ��
                judge_passwordj(); //��ʦ��½����
                break;
            case 2:   //�˳�����
                quit = 1;
            }
            break;


        case 1: //ѧ����
            viewx();
            printf("\n������ǰ�����Ž���ѡ��");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("���벻�Ϸ������������룺");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:  //��ѯ���Գɼ�
                find_scorex(); //�ɼ���ѯ����
                break;
            case 1:  //��ѯƽ����,��߷�
                find_else();
                break;
            case 2:  //��ѯ����
                find_range();
                break;
            case 3:  //�޸��û���
                change_id();
                break;
            case 4:  //�޸�����
                change_passwordx();
                break;
            case 5:  //������һ����
                k = 0;
                break;
            case 6:  //�˳�ϵͳ
                quit = 1;
            }
            break;


        case 2:   //��ʦ��
            viewj();
            printf("\n������ǰ�����Ž���ѡ��");
            while(scanf("%d",&j)==0){
                fflush(stdin);
                printf("���벻�Ϸ������������룺");
            }
            fflush(stdin);
            switch(j)
            {
            case 0:   // �޸Ľ�ʦ��½����
                change_passwordj();  //�����޸ĺ���
                break;
            case 1:   //����ѧ���ɼ�
                new_score();
                break;
            case 2:   //ɾ������Ϣ¼��
                delete_score();
                break;
            case 3:   //�޸�ѧ����Ϣ
                change_score();
                break;
            case 4:   //��ѯѧ���ɼ�
                find_scorej();
                break;
            case 5:   //������ҳ��
                k = 0;
                break;
            case 6:   //�˳�����
                quit = 1;
            }
        }
        if(quit == 1){
            break;
        }
    }
    end_(); //��������
}
