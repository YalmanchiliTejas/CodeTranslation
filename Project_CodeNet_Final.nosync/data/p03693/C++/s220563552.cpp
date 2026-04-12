#include<iostream>
using namespace std;
int main(){
int r,g,b;
cin>>r>>g>>b;
long long res;
res=r*100+g*10+b;
if(res%4==0)cout<<"YES\n";
else
cout<<"NO\n";
return 0;
}
