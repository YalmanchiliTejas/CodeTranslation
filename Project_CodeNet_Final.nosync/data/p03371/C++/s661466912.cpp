#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stdio.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    int mx=a*x+b*y;
    if(x<y){
        swap(x,y);
        swap(a,b);
    }
    int cnt=0;
    y=y-1;
    x=x-1;
    
    while(x>=0){
        cnt++;
        
        long long sum=x*a+y*b+c*cnt*2;
        if(mx>sum){
            mx=sum;
        }
        x=x-1;
        if(y>0){y=y-1;}
        else y=0;
    }
    
    cout<<mx<<endl;
    

return 0;
}