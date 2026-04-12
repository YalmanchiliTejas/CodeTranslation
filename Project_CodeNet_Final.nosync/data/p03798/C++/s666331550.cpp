#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int gh(char *str,char *ch,int n) {
    for(int i=1; i<n; i++) {
        if(i<n-2) {
            if(str[i]=='o') {
                if(ch[i]=='S') {
                    ch[i+1]=ch[i-1];
                } else {
                    if(ch[i-1]=='S') ch[i+1]='W';
                    else ch[i+1]='S';
                }
            } else {
                if(ch[i]=='S') {
                    if(ch[i-1]=='S') ch[i+1]='W';
                    else ch[i+1]='S';
                } else {
                    ch[i+1]=ch[i-1];
                }
            }
        }
        else if(i==n-2) {
            if(str[i]=='o') {
                if(ch[i]=='S') {
                    if(ch[i+1]!=ch[i-1]) {
                        return 1;
                    }
                }
                else {
                    if(ch[i+1]==ch[i-1]){
                        return 1;
                    }
                }
            }
            else{
                if(ch[i]=='S'){
                    if(ch[i+1]==ch[i-1]){
                        return 1;
                    }
                }
                else{
                    if(ch[i+1]!=ch[i-1]) {
                        return 1;
                    }
                }
            }
        }
        else if(i==n-1){
            if(str[i]=='x'){
                if(ch[i]=='S') {
                    if(ch[n-2]==ch[0]) return 1;
                }
                else{
                    if(ch[n-2]!=ch[0]) return 1;
                }
            }
            else{
                if(ch[i]=='S'){
                    if(ch[n-2]!=ch[0]) return 1;
                }
                else{
                    if(ch[n-2]==ch[0]) return 1;
                }
            }
        }
    }
    return 0;
}
int main() {
    char str[N];
    char ch[N];
    int n;
    int flag=0;
    scanf("%d",&n);
    scanf("%s",str);
    ch[0]='S';
    if(str[0]=='o') {
        memset(ch,0,sizeof(ch));
        ch[0]='S';
        ch[1]='S';
        ch[n-1]='S';
        flag=gh(str,ch,n);
        if(flag==0) {
            for(int i=0; i<n; i++) printf("%c",ch[i]);
            puts("");
            return 0;
        } else {
            memset(ch,0,sizeof(ch));
            ch[0]='S';
            ch[1]='W';
            ch[n-1]='W';
            flag=gh(str,ch,n);
            if(flag==0){
                for(int i=0;i<n;i++) printf("%c",ch[i]);
                puts("");
                return 0;
            }
        }
    }
    else{
        memset(ch,0,sizeof(ch));
        ch[0]='S';
        ch[1]='S';
        ch[n-1]='W';
        flag=gh(str,ch,n);
        if(flag==0){
            for(int i=0;i<n;i++) printf("%c",ch[i]);
            puts("");
            return 0;
        }
        else{
            memset(ch,0,sizeof(ch));
            ch[0]='S';
            ch[1]='W';
            ch[n-1]='S';
            flag=gh(str,ch,n);
            if(flag==0){
                for(int i=0;i<n;i++) printf("%c",ch[i]);
                puts("");
                return 0;
            }
        }
    }
    ch[0]='W';
    if(str[0]=='o'){
        memset(ch,0,sizeof(ch));
        ch[0]='W';
        ch[1]='S';
        ch[n-1]='W';
        flag=gh(str,ch,n);
        if(flag==0){
            for(int i=0;i<n;i++) printf("%c",ch[i]);
            puts("");
            return 0;
        }
        else{
            ch[0]='W';
            ch[1]='W';
            ch[n-1]='S';
            flag=gh(str,ch,n);
            if(flag==0){
                for(int i=0;i<n;i++) printf("%c",ch[i]);
                puts("");
                return 0;
            }
        }
    }
    else{
        memset(ch,0,sizeof(ch));
        ch[0]='W';
        ch[1]='S';
        ch[n-1]='S';
        flag=gh(str,ch,n);
        if(flag==0){
            for(int i=0;i<n;i++) printf("%c",ch[i]);
            puts("");
        }
        else{
            ch[0]='W';
            ch[1]='W';
            ch[n-1]='W';
            flag=gh(str,ch,n);
            if(flag==0){
                for(int i=0;i<n;i++) printf("%c",ch[i]);
                puts("");
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
