// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i],a[i]*=(-1);
    vector<int> nib;
    rep(i,0,n){
        auto j = upper_bound(nib.begin(),nib.end(),a[i]);
        if (j==nib.end()){
            nib.push_back(a[i]);
        }else{
            *j = a[i];
        }
    }
    cout<<nib.size()<<endl;
}