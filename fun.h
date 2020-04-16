
typedef struct student{
    char id[14]; // �û���
    char id_password[14]; //�û�����
    char num[14];//ѧ��ѧ��
    char childclass[14];// ѧ���༶
    char name[10];//ѧ������
    int score;//�ϴ��ĳɼ�
    struct student *next;//��һ��ѧ����ָ��
}stu;

char idd[20], guess[20],password[20]; //��ʦ��½����ʹ��
FILE * fp;  //�ļ�ָ��
int k = 0, j, quit = 0; // ��ҳ�����
stu *head, *p, *n, *student_pt;// ����ָ��

void viewa(void){
    printf("###################################################\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#               #ѧ���ɼ���ѯϵͳ#                #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                 0��ѧ����½                     #\n");
    printf("#                 1����ʦ��½                     #\n");
    printf("#                 2���˳�ϵͳ                     #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("###################################################\n");
    return;
}

void viewx(void){
    printf("###################################################\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#              #ѧ���ɼ���ѯѧ����#               #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                0����ѯ���Գɼ�                  #\n");
    printf("#                1����ѯƽ������߷�              #\n");
    printf("#                2����ѯ����                      #\n");
    printf("#                3���޸��û���                    #\n");
    printf("#                4���޸�����                      #\n");
    printf("#                5��������һ����                  #\n");
    printf("#                6���˳�ϵͳ                      #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("###################################################\n");
    return;
}

void viewj(void){
    printf("###################################################\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#            #ѧ���ɼ���ѯϵͳ��ʦ��#             #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#               0���޸Ľ�ʦ��½����               #\n");
    printf("#               1������ѧ���ɼ�                   #\n");
    printf("#               2��ɾ��ѧ����Ϣ                   #\n");
    printf("#               3���޸�ѧ����Ϣ                   #\n");
    printf("#               4����ѯѧ���ɼ�                   #\n");
    printf("#               5��������һ����                   #\n");
    printf("#               6���˳�ϵͳ                       #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("###################################################\n");
    return;
}


void start(void)//�ɼ����ݳ�ʼ������
{
    fp = fopen("student.txt", "r");
    head = (stu*)malloc(sizeof(stu));
    p = n = head;
    head->next = NULL;
    n = (stu*)malloc(sizeof(stu));// ѧ�ţ��༶���������ɼ�
    while(fscanf(fp, "%s %s %s %s %s %d", &n->id, &n->id_password
                 , &n->num, &n->childclass, &n->name, &n->score)>1){
        p->next = n;
        p = n;
        n = (stu*)malloc(sizeof(stu));
    }
    p->next = NULL;
    free(n);
    fclose(fp);
    return;
}

void write(void) // �ṹ������д���ļ�
{
    p = n = head;
    fp = fopen("student.txt", "w");
    do{
        n = p->next;
        fprintf(fp,"%s    %s    %s    %s    %s    %d\n", n->id
                , n->id_password, n->num, n->childclass, n->name, n->score);
        p = n;
    }while(n->next);
    fclose(fp);
    return;
}


stu * find_student(char *numm) // ����ѧ����Ϣ����
{
    p = n =head;
    if(!head->next){
        return NULL;
    }
    do{
        n = p->next;
        if(!strcmp(n->num,numm)){
            return n;
        }
        p = n;
    }while(n->next);
    return NULL;
}


void judge_passwordx(void)//ѧ����½����
{
    printf("�������û���������(��ʼ�û���Ϊѧ�ţ�����Ϊ111111)��");
    scanf("%s%s", &idd, &guess);
    fflush(stdin);
    p = n = head;
    if(!head->next){
        printf("�û���������������󣡣�");
        getchar();
        return;
    }
    do{
        n = p->next;
        if(!strcmp(n->id, idd)){
            if(!strcmp(n->id_password, guess)){
                k = 1;
                student_pt = n;
                return;
            }
        }
        p = n;
    }while(n->next);
    printf("�û���������������󣡣�");
    getchar();
    return;
}


void judge_passwordj(void)//��ʦ��½����
{
    printf("�������ʦ��½����(��ʼ����Ϊ111111)��");
    fp = fopen("teacher.txt","r"); // �������ļ�
    fscanf(fp,"%s",&password);
    fclose(fp);   //�ر������ļ�
    gets(guess);
    if (strcmp(guess,password)){//�ж������Ƿ���ȷ
        printf("\n       ������󣡣�");
        fflush(stdin);
        getchar();
    }
    else{
        k=2; //�ɹ�����
    }
    return;
}



//  ѧ���˺���

void find_scorex(void)  //�ɼ���ѯ����
{
    printf("\n�ɼ��Ѳ鵽��\nѧ�ţ�%s\n�༶��%s\n������%s\n�ɼ���%d\n"
            , student_pt->num, student_pt->childclass, student_pt->name, student_pt->score);
    getchar();
    return;
}


void find_else(void) // ��ѯƽ������߷ֺ���
{
    p = n = head;
    int sum = 0, maxscore = 0, i = 0;
    do{
        n = p->next;
        sum += n->score;
        ++i;
        if(n->score > maxscore){
            maxscore = n->score;
        }
        p = n;
    }while(n->next);
    printf("\n����ͬѧ��ƽ����Ϊ��%d\n��߷�Ϊ��%d\n", sum/i, maxscore);
    getchar();
    return;
}


void find_range() //��ѯ����
{
    n = head;
    printf("%s", student_pt->name);
    int ss1 = 1, ss2 = 0, ss3 = 1, ss4 = 0;
    do{
        n = n->next;
        if(!strcmp(n->childclass,student_pt->childclass)){
            if(n->score > student_pt->score){
                ++ss3;
            }
            ++ss4;
        }
        if(n->score > student_pt->score){
            ++ss1;
        }
        ++ss2;
    }while(n->next);
    printf("ͬѧ���������Ϊ%d������%d�ˣ���", ss1, ss2);
    printf("\n�ڰ��ڵ�����Ϊ%d(����%d��)��\n", ss3, ss4);
    getchar();
    return;
}


void change_id(void)  //�û����޸ĺ���
{
    printf("\n�������µ��û���(���Ȳ�Ҫ����14���ַ�)\n: ");
    gets(student_pt->id);
    write();
    fflush(stdin);
    getchar();
    return;
}

void change_passwordx(void)  //�����޸ĺ���
{
    printf("������ԭ��½���룺");
    gets(guess); //��������
    if (strcmp(guess,student_pt->id_password)){//�ж������Ƿ���ȷ
        printf("\n       �������!!");
    }
    else{
        printf("������������(���볤�Ȳ�����14���ַ�)\n �� ");
        gets(student_pt->id_password);
        write();
        printf("�����޸ĳɹ�");
    }
    fflush(stdin);
    getchar();
    return;
}




//  ��ʦ�˺���
void change_passwordj(void)  //�����޸ĺ���
{
    printf("�������ʦԭ��½���룺");
    fp = fopen("teacher.txt","r"); // �������ļ�
    fscanf(fp,"%s",&password);
    fclose(fp);   //�ر������ļ�
    gets(guess); //��������
    if (strcmp(guess,password)){//�ж������Ƿ���ȷ
        printf("\n       �������!!");
        fflush(stdin);
        getchar();
    }
    else{
        printf("������������(���볤�Ȳ�����14���ַ�)\n �� ");
        gets(guess);
        fp=fopen("teacher.txt","w");//�������ļ�
        fprintf(fp,"%s",guess);
        fclose(fp); //�ر������ļ�
        printf("�����޸ĳɹ�");
        getchar();
    }
    return;
}


void new_score(void) //�½�ѧ����Ϣ
{
    p = head;
    printf("����������ѧ����ѧ�ţ��༶���������ɼ�\n");
    printf("(��:14196666  �������һ��  ����   85)��\n");
    n = (stu *)malloc(sizeof(stu));
    if(scanf("%s%s%s%d", &n->num, &n->childclass, &n->name, &n->score) == 4){
        strcpy(n->id_password, "111111");
        strcpy(n->id, n->num);
        p = p->next;
        printf("\n   �ɼ���¼�룡");
        head->next = n;
        n->next = p;
        write();
    }
    else{
        printf("����ȷ����ѧ����Ϣ!!!");
        free(n);
    }
    fflush(stdin);
    getchar();
    return;
}


void delete_score(void) // ɾ��ѧ����Ϣ
{
    char numm[14];
    printf("����������ɾ����ѧ��ѧ��:");
    gets(numm);
    fflush(stdin);
    p = find_student(numm);
    if(p){
        printf("\n���ĳɼ��Ѳ鵽��\nѧ�ţ�%s\n�༶��%s\n������%s\n�ɼ���%d"
               , n->num, n->childclass, n->name, n->score);
        printf("\n(ȷ��ɾ�������롮y�� )\n");
        if(getchar() == 'y'){
            n = head;
            do{
                if(n->next == p){
                    n->next = p->next;
                    free(p);
                    break;
                }
                n = n->next;
            }while(n->next);
            write();
            printf("\n�ɼ���ɾ��");
        }
    }
    else{
        printf("\nδ�鵽��ѧ������Ϣ��");
    }
    fflush(stdin);
    getchar();
    return;
}


void change_score(void)  //�޸�ѧ���ɼ�����
{
    int scoree;
    char numm[14];
    printf("������Ҫ�޸ĳɼ�ѧ����ѧ�ţ�");
    gets(numm);
    p = find_student(numm);
    if(p){
        printf("��ѧ��֮ǰ�ĳɼ�Ϊ��%d���������޸ĺ�ĳɼ���\n", p->score);
        scanf("%d", &scoree);
        p->score = scoree;
        write();
        printf("�޸ĳɹ�����");
    }
    else{
        printf("δ�鵽��ѧ����Ϣ����\n");
    }
    fflush(stdin);
    getchar();
    return;
}


void find_scorej(void)  //�ɼ���ѯ����
{
    char number[14];
    printf("������ѧ�Ž��в�ѯ��");
    gets(number);
    fflush(stdin);
    p = find_student(number);
    if(p){
        printf("\n��ѧ���ĳɼ��Ѳ鵽��\nѧ�ţ�%s\n�༶��%s\n������%s\n�ɼ���%d\n"
               , n->num, n->childclass, n->name, n->score);
    }
    else{
        printf("û�в鵽��ѧ�ŵ���Ϣ\n");
    }
    getchar();
    return;
}


void end_(void)
{
    p = n = head;
    do{
        n = p->next;
        free(p);
        p = n;
    }while(p->next);
    free(p);
    printf("\n��лʹ��...\n");
    return;
}
