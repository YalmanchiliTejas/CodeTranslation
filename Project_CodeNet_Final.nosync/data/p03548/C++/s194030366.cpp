#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) {
    
   int x,y,z;
   cin>>x>>y>>z;

   int sum;
   if(x%(y+z)>=z)cout<<x/(y+z)<<endl;
   else cout<<x/(y+z)-1<<endl;

    return 0;
}