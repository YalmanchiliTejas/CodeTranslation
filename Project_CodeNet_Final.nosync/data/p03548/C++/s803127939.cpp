#include <bits/stdc++.h>
using namespace std;
int rez;
int lung;
int x,y,z;
int main(){
   cin>>x>>y>>z;
   lung=x-z;
   rez=lung/(y+z);
   cout<<rez<<endl;
}