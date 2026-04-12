#include <bits/stdc++.h>
using namespace std;
char ans[100050];
char in[100050];
int n;
int check(char x,char y){
    memset(ans,'!',sizeof(ans));
    ans[0] = x;
    ans[1] = y;
    for(int i = 1;i <= n;i ++){
        if(ans[i] == 'S'){
            if(in[i] == 'x'){
                if(ans[i - 1] == 'S'){ans[i + 1] = 'W';}
                else{ans[i + 1] = 'S';}
            }
            else{
                if(ans[i - 1] == 'S'){ans[i + 1] = 'S';}
                else{ans[i + 1] = 'W';}
            }
        }
        else{
            if(in[i] == 'x'){
                if(ans[i - 1] == 'S'){ans[i + 1] = 'S';}
                else{ans[i + 1] = 'W';}
            }
            else{
                if(ans[i - 1] == 'S'){ans[i + 1] = 'W';}
                else{ans[i + 1] = 'S';}
            }
        }
    }
    //for(int i = 0;i < n + 2;i ++){printf("%c",ans[i]);}printf("\n");
    if(ans[0] == ans[n] && ans[1] == ans[n + 1]){return 1;}
    return 0;
}

int main(){
    scanf("%d",&n);
    scanf("%s",in);
    in[n] = in[0];
    in[n + 1] = in[1];
    in[n + 2] = '\0';
    //printf("%s\n",in);
    if(check('W','W') == 1){
        for(int i = 0;i < n;i ++){
            printf("%c",ans[i]);
        }printf("\n");
    }
    else if(check('W','S') == 1){
        for(int i = 0;i < n;i ++){
            printf("%c",ans[i]);
        }printf("\n");
    }
    else if(check('S','S') == 1){
        for(int i = 0;i < n;i ++){
            printf("%c",ans[i]);
        }printf("\n");
    }
    else if(check('S','W') == 1){
        for(int i = 0;i < n;i ++){
            printf("%c",ans[i]);
        }printf("\n");
    }
    else{
        printf("-1\n");
    }
    return 0;
}
