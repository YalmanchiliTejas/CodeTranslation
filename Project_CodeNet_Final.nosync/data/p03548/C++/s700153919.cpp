#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int tmp=0,count=0,Yaju=114514;
    while(Yaju){
        tmp+=z;
        tmp+=y;
        if(tmp<x)count++;
        else{
            if(tmp-y>x){
                count--;
                Yaju-=114514;
            }else{
                Yaju-=114514;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}