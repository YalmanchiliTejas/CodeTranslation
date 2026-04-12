#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(int n, ll x){
    if(n==0)  return 1;
    ll len = (1LL<<(n+2)) - 3;
    ll num = (1LL<<(n+1)) -1;
    ll cent = num ;
   // cout<<cent<<endl;
    ll len2 = (1LL<<(n+1)) - 3;
    if(x==1) return 0;
    else if(x<cent) return solve(n-1,x-1);
    else if(x==cent) return solve(n-1,len2)+1;
    else if(len> x&&x<len) return solve(n-1,len2) + 1 + solve(n-1, x-cent); 
    else if(len ==x ) return 2*solve(n-1,len2) + 1; 
    else return num;
}
int main(void){
    int n; cin>>n;
    ll x; cin>>x;
    
    cout<< solve(n,x) <<endl;
}
