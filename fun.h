
typedef struct student{
    char id[14]; // 用户名
    char id_password[14]; //用户密码
    char num[14];//学生学号
    char childclass[14];// 学生班级
    char name[10];//学生姓名
    int score;//上传的成绩
    struct student *next;//下一个学生的指针
}stu;

char idd[20], guess[20],password[20]; //教师登陆密码使用
FILE * fp;  //文件指针
int k = 0, j, quit = 0; // 主页面参数
stu *head, *p, *n, *student_pt;// 链表指针

void viewa(void){
    printf("###################################################\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#               #学生成绩查询系统#                #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                 0、学生登陆                     #\n");
    printf("#                 1、教师登陆                     #\n");
    printf("#                 2、退出系统                     #\n");
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
    printf("#              #学生成绩查询学生端#               #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#                0、查询考试成绩                  #\n");
    printf("#                1、查询平均分最高分              #\n");
    printf("#                2、查询排名                      #\n");
    printf("#                3、修改用户名                    #\n");
    printf("#                4、修改密码                      #\n");
    printf("#                5、返回上一界面                  #\n");
    printf("#                6、退出系统                      #\n");
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
    printf("#            #学生成绩查询系统教师端#             #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("#               0、修改教师登陆密码               #\n");
    printf("#               1、新增学生成绩                   #\n");
    printf("#               2、删除学生信息                   #\n");
    printf("#               3、修改学生信息                   #\n");
    printf("#               4、查询学生成绩                   #\n");
    printf("#               5、返回上一界面                   #\n");
    printf("#               6、退出系统                       #\n");
    printf("#                                                 #\n");
    printf("#                                                 #\n");
    printf("###################################################\n");
    return;
}


void start(void)//成绩数据初始化函数
{
    fp = fopen("student.txt", "r");
    head = (stu*)malloc(sizeof(stu));
    p = n = head;
    head->next = NULL;
    n = (stu*)malloc(sizeof(stu));// 学号，班级，姓名，成绩
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

void write(void) // 结构体数据写入文件
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


stu * find_student(char *numm) // 查找学生信息函数
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


void judge_passwordx(void)//学生登陆函数
{
    printf("请输入用户名和密码(初始用户名为学号，密码为111111)：");
    scanf("%s%s", &idd, &guess);
    fflush(stdin);
    p = n = head;
    if(!head->next){
        printf("用户名或密码输入错误！！");
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
    printf("用户名或密码输入错误！！");
    getchar();
    return;
}


void judge_passwordj(void)//教师登陆函数
{
    printf("请输入教师登陆密码(初始密码为111111)：");
    fp = fopen("teacher.txt","r"); // 打开密码文件
    fscanf(fp,"%s",&password);
    fclose(fp);   //关闭密码文件
    gets(guess);
    if (strcmp(guess,password)){//判断密码是否正确
        printf("\n       密码错误！！");
        fflush(stdin);
        getchar();
    }
    else{
        k=2; //成功进入
    }
    return;
}



//  学生端函数

void find_scorex(void)  //成绩查询函数
{
    printf("\n成绩已查到：\n学号：%s\n班级：%s\n姓名：%s\n成绩：%d\n"
            , student_pt->num, student_pt->childclass, student_pt->name, student_pt->score);
    getchar();
    return;
}


void find_else(void) // 查询平均分最高分函数
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
    printf("\n所有同学的平均分为：%d\n最高分为：%d\n", sum/i, maxscore);
    getchar();
    return;
}


void find_range() //查询排名
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
    printf("同学，你的排名为%d（共有%d人）。", ss1, ss2);
    printf("\n在班内的排名为%d(共有%d人)。\n", ss3, ss4);
    getchar();
    return;
}


void change_id(void)  //用户名修改函数
{
    printf("\n请输入新的用户名(长度不要超过14个字符)\n: ");
    gets(student_pt->id);
    write();
    fflush(stdin);
    getchar();
    return;
}

void change_passwordx(void)  //密码修改函数
{
    printf("请输入原登陆密码：");
    gets(guess); //输入密码
    if (strcmp(guess,student_pt->id_password)){//判断密码是否正确
        printf("\n       密码错误!!");
    }
    else{
        printf("请输入新密码(密码长度不超过14个字符)\n ： ");
        gets(student_pt->id_password);
        write();
        printf("密码修改成功");
    }
    fflush(stdin);
    getchar();
    return;
}




//  教师端函数
void change_passwordj(void)  //密码修改函数
{
    printf("请输入教师原登陆密码：");
    fp = fopen("teacher.txt","r"); // 打开密码文件
    fscanf(fp,"%s",&password);
    fclose(fp);   //关闭密码文件
    gets(guess); //输入密码
    if (strcmp(guess,password)){//判断密码是否正确
        printf("\n       密码错误!!");
        fflush(stdin);
        getchar();
    }
    else{
        printf("请输入新密码(密码长度不超过14个字符)\n ： ");
        gets(guess);
        fp=fopen("teacher.txt","w");//打开密码文件
        fprintf(fp,"%s",guess);
        fclose(fp); //关闭密码文件
        printf("密码修改成功");
        getchar();
    }
    return;
}


void new_score(void) //新建学生信息
{
    p = head;
    printf("请依次输入学生的学号，班级，姓名，成绩\n");
    printf("(如:14196666  软件工程一班  张三   85)：\n");
    n = (stu *)malloc(sizeof(stu));
    if(scanf("%s%s%s%d", &n->num, &n->childclass, &n->name, &n->score) == 4){
        strcpy(n->id_password, "111111");
        strcpy(n->id, n->num);
        p = p->next;
        printf("\n   成绩已录入！");
        head->next = n;
        n->next = p;
        write();
    }
    else{
        printf("请正确输入学生信息!!!");
        free(n);
    }
    fflush(stdin);
    getchar();
    return;
}


void delete_score(void) // 删除学生信息
{
    char numm[14];
    printf("请输入你想删除的学生学号:");
    gets(numm);
    fflush(stdin);
    p = find_student(numm);
    if(p){
        printf("\n您的成绩已查到：\n学号：%s\n班级：%s\n姓名：%s\n成绩：%d"
               , n->num, n->childclass, n->name, n->score);
        printf("\n(确认删除请输入‘y’ )\n");
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
            printf("\n成绩已删除");
        }
    }
    else{
        printf("\n未查到该学生的信息！");
    }
    fflush(stdin);
    getchar();
    return;
}


void change_score(void)  //修改学生成绩函数
{
    int scoree;
    char numm[14];
    printf("请输入要修改成绩学生的学号：");
    gets(numm);
    p = find_student(numm);
    if(p){
        printf("此学生之前的成绩为：%d，请输入修改后的成绩：\n", p->score);
        scanf("%d", &scoree);
        p->score = scoree;
        write();
        printf("修改成功！！");
    }
    else{
        printf("未查到该学生信息！！\n");
    }
    fflush(stdin);
    getchar();
    return;
}


void find_scorej(void)  //成绩查询函数
{
    char number[14];
    printf("请输入学号进行查询：");
    gets(number);
    fflush(stdin);
    p = find_student(number);
    if(p){
        printf("\n该学生的成绩已查到：\n学号：%s\n班级：%s\n姓名：%s\n成绩：%d\n"
               , n->num, n->childclass, n->name, n->score);
    }
    else{
        printf("没有查到该学号的信息\n");
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
    printf("\n感谢使用...\n");
    return;
}
