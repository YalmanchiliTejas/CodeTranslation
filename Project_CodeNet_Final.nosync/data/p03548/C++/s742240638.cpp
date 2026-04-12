#include <bits/stdc++.h>
using namespace std;
int main()
{
        int x,y,z,t=0;
        cin>>x>>y>>z;
        x-=(2*z);
        while(x>=y){
            x-=(y+z);
            t++;
        }
        cout<<t;
   return 0;
   }