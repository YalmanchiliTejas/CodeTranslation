#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[12];
    for(int i=0;i<12;i++)cin>>a[i];
    sort(a,a+12);
    bool masatoy=true;
    for(int i=0;i<12;i=i+2){
        if(a[i]!=a[i+1])masatoy=false;
    }
    if(masatoy==true)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}