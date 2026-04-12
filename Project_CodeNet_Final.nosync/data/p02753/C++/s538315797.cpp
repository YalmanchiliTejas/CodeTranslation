#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}
using namespace std;
int main(){
   string s;
   cin>>s;
   bool f;
   (s[0]==s[1] && s[1]==s[2])? cout<<"No":cout<<"Yes";
   
return 0;
}