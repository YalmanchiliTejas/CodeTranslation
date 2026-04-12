#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) {
    
   int r,g,b;
   cin>>r>>g>>b;
    int n;

    n=r*100+g*10+b;
    if(n%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}