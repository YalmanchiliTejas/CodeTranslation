#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000+10

using namespace std;
char y[MAXN];//0表示x，1表示o
bool an[MAXN];//0表示狼
int n;
void print(){
    for(int i=1;i<=n;i++){
        if(an[i]) printf("S");
        else printf("W");
    }
    printf("\n");
    exit(0);
}
bool fd(){
    for(int i=2;i<=n;i++){//羊说o和狼说x，前后应该相同
        if(an[i]){//羊
            if(y[i]=='o')   an[i+1]=an[i-1];
            else an[i+1]=!an[i-1];
        }
        else {
            if(y[i]=='o')   an[i+1]=!an[i-1];
            else an[i+1]=an[i-1];
        }
    }
    if(an[n]){//n是羊
        if(y[n]=='o'&&an[1]==an[n-1]){//羊说相同确实相同
            if(an[1]){//羊
                if(y[1]=='o'&&an[2]==an[n]) print();
                else if(y[1]=='x'&&an[2]!=an[n])    print();
            }
            else {//狼
                if(y[1]=='o'&&an[2]!=an[n]) print();
                else if(y[1]=='x'&&an[2]==an[n])    print();
            }
        }
        else if(y[n]=='x'&&an[1]!=an[n-1]) {//羊说不同
            if(an[1]){//羊
                if(y[1]=='o'&&an[2]==an[n]) print();
                else if(y[1]=='x'&&an[2]!=an[n])    print();
            }
            else {//狼
                if(y[1]=='o'&&an[2]!=an[n]) print();
                else if(y[1]=='x'&&an[2]==an[n])    print();
            }
        }
    }
    else {//n是狼
        if(y[n]=='o'&&an[1]!=an[n-1]){//羊说相同确实相同
            if(an[1]){//羊
                if(y[1]=='o'&&an[2]==an[n]) print();
                else if(y[1]=='x'&&an[2]!=an[n])    print();
            }
            else {//狼
                if(y[1]=='o'&&an[2]!=an[n]) print();
                else if(y[1]=='x'&&an[2]==an[n])    print();
            }
        }
        else if(y[n]=='x'&&an[1]==an[n-1]) {//羊说不同
            if(an[1]){//羊
                if(y[1]=='o'&&an[2]==an[n]) print();
                else if(y[1]=='x'&&an[2]!=an[n])    print();
            }
            else {//狼
                if(y[1]=='o'&&an[2]!=an[n]) print();
                else if(y[1]=='x'&&an[2]==an[n])    print();
            }
        }
    }
}

int main(){
    char a;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        y[i]=getchar();
    }
    an[1]=1,an[2]=1;//都是羊
    fd();
    an[1]=0,an[2]=0;//都是狼
    fd();
    an[1]=1,an[2]=0;//羊 狼
    fd();
    an[1]=0,an[2]=1;//狼 羊
    fd();
    printf("-1");
    return 0;
}
