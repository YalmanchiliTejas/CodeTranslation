#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,ans=0;
    cin>>h>>w;
    char ch[8][8];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>ch[i][j];
            if(ch[i][j]=='#')ans++;
        }
    }
    if(ans==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}