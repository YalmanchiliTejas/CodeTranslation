#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF=1e5+100;
int f[INF],n;
string s;
bool fun(int x,int y,int flag)
{
    memset(f,0,sizeof(f));
    f[0]=x;
    f[1]=y;
    for(int i=1; i<n-1; i++)
    {
        if(f[i]==1)
        {
            if(s[i]=='o')
            {
                f[i+1]=f[i-1];
            }
            else
            {
                f[i+1]=-f[i-1];
            }
        }
        else
        {
            if(s[i]=='o')
            {
                f[i+1]=-f[i-1];
            }
            else
            {
                f[i+1]=f[i-1];
            }
        }
    }
    if(flag){
        if(x==1){
            if(f[1]==f[n-1]){
                if(s[n-1]=='o'){
                    if(f[n-1]==1 && f[n-2]==f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]!=f[0])  return 1;
                    return 0;
                }
                else{
                    if(f[n-1]==1 && f[n-2]!=f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]==f[0])  return 1;
                    return 0;
                }
            }
            return 0;
        }
        else{
            if(f[1]!=f[n-1]){
                if(s[n-1]=='o'){
                    if(f[n-1]==1 && f[n-2]==f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]!=f[0])  return 1;
                    return 0;
                }
                else{
                    if(f[n-1]==1 && f[n-2]!=f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]==f[0])  return 1;
                    return 0;
                }
            }
            return 0;
        }
    }
    else{
        if(x==1){
            if(f[1]!=f[n-1]){
                if(s[n-1]=='o'){
                    if(f[n-1]==1 && f[n-2]==f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]!=f[0])  return 1;
                    return 0;
                }
                else{
                    if(f[n-1]==1 && f[n-2]!=f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]==f[0])  return 1;
                    return 0;
                }
            }
            return 0;
        }
        else{
            if(f[1]==f[n-1]){
                if(s[n-1]=='o'){
                    if(f[n-1]==1 && f[n-2]==f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]!=f[0])  return 1;
                    return 0;
                }
                else{
                    if(f[n-1]==1 && f[n-2]!=f[0])  return 1;
                    if(f[n-1]==-1 && f[n-2]==f[0])  return 1;
                    return 0;
                }
            }
            return 0;
        }
    }
}
void pri()
{
    for(int i=0; i<n; i++){
        if(f[i]==1) cout<<"S";
        else  cout<<"W";
    }
    cout<<endl;
    return ;
}
int main()
{
    cin>>n>>s;
    if(s[0]=='o'){
        if(fun(1,1,1)){
            pri();
            return 0;
        }
        if(fun(1,-1,1)){
            pri();
            return 0;
        }
        if(fun(-1,1,1)){
            pri();
            return 0;
        }
        if(fun(-1,-1,1)){
            pri();
            return 0;
        }
    }
    else{
        if(fun(1,1,0)){
            pri();
            return 0;
        }
        if(fun(1,-1,0)){
            pri();
            return 0;
        }
        if(fun(-1,1,0)){
            pri();
            return 0;
        }
        if(fun(-1,-1,0)){
            pri();
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
