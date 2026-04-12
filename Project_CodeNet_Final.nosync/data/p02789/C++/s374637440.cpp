#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        //cin>>n>>m;
        if(n==m)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
