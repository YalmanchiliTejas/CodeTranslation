#include<bits/stdc++.h>
#define ll long long
#define inf 999999999999
#define F first
#define S second
#define eb emplace_back
#define mp make_pair
#define P(x) cout<<__LINE__ <<": "<<#x<<' '<<(x)<<'\n'
#define dbg cout<<__LINE__ <<": 0manush\n"
#define read(x) freopen("input.txt","r",stdin)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 200009
#define mod 1000000007
using namespace std;

int main(){//read(x);
//fast;
ll r,g,h,i,j,x,t,y,z=0,e,f,a,b,c,d,n,l;
string s,u,v;
cin>>n;
l=0;
ll m[n];
for(i=0;i<n;i++){
    cin>>m[i];
    l=(l+m[i])%mod;
}a=0;
for(i=0;i<n-1;i++){
    l=(l+mod-m[i])%mod;
    a=(a+(l*m[i])%mod)%mod;
}
cout<<a<<endl;
}





















