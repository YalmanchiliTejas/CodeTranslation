#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
ll RF(int n,ll x,vector<ll> a,vector<ll> p){
    if(n==0) return (x<=0) ? 0 : 1;
    else if(x<=1+a[n-1]) return RF(n-1,x-1,a,p);
    else return p[n-1]+1+RF(n-1,x-2-a[n-1],a,p);
}
int main(){
    int n;cin >> n;
    ll x;cin >> x;
    vector<ll> a(n+1),p(n+1);
    a[0]=1;
    p[0]=1;
    for(int i=0;i<n;i++){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    cout << RF(n,x,a,p) << endl;
    return 0;
}