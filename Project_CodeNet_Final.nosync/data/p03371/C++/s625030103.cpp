#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <queue>
#include <deque>
#include <vector>
#define maxc 100010
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int main(){
   int a,b,c,x,y;
   cin>>a>>b>>c>>x>>y;
   if(c*2<=a+b){
        if(x>y){
            if(a>c*2)
                cout<<c*x*2<<endl;
            else
                cout<<c*y*2+(x-y)*a<<endl;
        }
        else{
            if(b>c*2)
                cout<<c*y*2<<endl;
            else
                cout<<c*x*2+(y-x)*b<<endl;
        }
   }
   else{
        if(a>c*2)
            cout<<c*2*x+b*y<<endl;
        else if(b>c*2)
            cout<<c*2*y+a*x<<endl;
        else
            cout<<a*x+b*y<<endl;
   }
   return 0;
}
