#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

ll patty(ll n,ll x){
    if(n==0) return 1ll;
    if(x==1) return 0ll;
    if(x==((1ll<<(n+2))-3ll)) return (1ll<<(n+1))-1ll;
    if(x<((1ll<<(n+1))-1ll)) return patty(n-1,x-1);
    if(x==((1ll<<(n+1))-1ll)) return 1ll<<n;
    if(x>((1ll<<(n+1))-1ll)) return (1ll<<n)+patty(n-1,x-((1ll<<(n+1))-1ll));
}
int main(){
    ll n,x;
    cin >> n >> x;
    cout << patty(n,x) << endl;
    return 0;
}