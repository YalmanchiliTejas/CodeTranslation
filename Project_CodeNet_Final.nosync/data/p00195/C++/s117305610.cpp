#include<cstdio>
#include<iostream>
using namespace std;
struct Date{
    int mx;
    int num;
};
int main(){
    while(1){
        int a[10]={0},b[10]={0};
        Date date;
        date.mx = 0;
        for(int i = 0; i < 5; i++){
            scanf("%d %d",&a[i],&b[i]);
            if(a[i] == 0 && b[i] == 0)goto end;
            if(date.mx < a[i]+b[i]){
                date.mx=a[i]+b[i];
                date.num = i;
            }
        }
        char d;
        switch(date.num){
            case 0:
                d = 'A';
                break;
            case 1:
                d = 'B';
                break;
            case 2:
                d = 'C';
                break;
            case 3:
                d = 'D';
                break;
            case 4:
                d = 'E';
                break;
        }
        printf("%c %d\n",d,date.mx);
    }
    end:
    return 0;
}