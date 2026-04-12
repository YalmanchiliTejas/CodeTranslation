#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int h,w;    cin>>h>>w;
    char m[h][w+1];
    for(int i=0;i<h;i++)cin>>m[i];

    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(m[j][i]=='#')break;
            if(j==h-1)for(int k=0;k<h;k++)m[k][i]='0';
        }
    }
    for(int i=0;i<h;i++)if(strchr(m[i],'#')==NULL)for(int k=0;k<w;k++)m[i][k]='0';
    bool flag;
    for(int i=0;i<h;i++,flag=false){
        for(int j=0;j<w;j++)if(m[i][j]!='0'){
            cout<<m[i][j];
            flag=true;
        }
        if(flag)cout<<endl;
    }
    return 0;
}