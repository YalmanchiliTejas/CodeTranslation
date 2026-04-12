#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[300005],ans[300005];
int n;
char dao(char a){
    if(a=='S') return 'W';
    if(a=='W') return 'S';
}
int deal(){
    for(int i=2;i<n;i++){
        if(s[i]=='o'){
            if(ans[i]=='S'){
                ans[i+1]=ans[i-1];
            }
            else{
                ans[i+1]=dao(ans[i-1]);
            }
        }
        else {
            if(ans[i]=='S'){
                ans[i+1]=dao(ans[i-1]);
            }
            else{
                ans[i+1]=ans[i-1];
            }
        }
    }
    int flag1=0,flag2=0;
    if(ans[1]=='S'){
        if(s[1]=='o'){
            if(ans[2]==ans[n]){
                flag1=1;
            }
        }
        else{
            if(ans[2]==dao(ans[n])){
                flag1=1;
            }
        }
    }
    else {
        if(s[1]=='o')
            if(ans[2]!=ans[n]) {
                flag1=1;
            }
        else
            if(ans[2]!=dao(ans[n])){
                flag1=1;
            }
    }
    if(ans[n]=='S'){
        if(s[n]=='o'){
            if(ans[1]==ans[n-1]){
                flag2=1;
            }
        }
        else{
            if(ans[1]==dao(ans[n-1])){
                flag2=1;
            }
        }
    }
    else {
        if(s[n]=='o'){
            if(ans[1]==dao(ans[n-1])){
                flag2=1;
            }
        }
        else{
            if(ans[1]==ans[n-1]){
                flag2=1;
            }
        }

    }
    if(flag1&&flag2) return 1;
    return 0;
}
int main(){

    scanf("%d%s",&n,s+1);
    ans[1]='S',ans[2]='S';
    if(deal()){
        printf("%s\n",ans+1);
        return 0;
    }
    ans[1]='S',ans[2]='W';
    if(deal()){
        printf("%s\n",ans+1);
        return 0;
    }
    ans[1]='W',ans[2]='S';
    if(deal()){
        printf("%s\n",ans+1);
        return 0;
    }
    ans[1]='W',ans[2]='W';
    if(deal()){
        printf("%s\n",ans+1);
        return 0;
    }
    printf("-1\n");
    return 0;
}
