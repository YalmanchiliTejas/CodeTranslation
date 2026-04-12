#include <bits/stdc++.h>
using namespace std;
int main (){
int a,b,c,d=0;
cin>>a>>b>>c;
a=a*100;
b=b*10;
d=a+b+c;
if (d%4==0)cout<<"YES";
else
    cout <<"NO";
return 0;
}



