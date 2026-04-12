#include <iostream>
using namespace std;
int main(void){
    int f=1,n,sum=0,i;
    cin>>n;
    int d[n];
    for(i=0;i<n;++i){
        cin>>d[i];;
    }
    for(i=0;i<n;++i){
        sum=max(sum-10,d[i]);
        if(sum<10)f=0;
    }
    sum=0;
    for(i=n-1;i>=0;--i){
        sum=max(sum-10,d[i]);
        if(sum<10)f=0;
    }
    if(f)cout<<"yes\n";
    else cout<<"no\n";
}

