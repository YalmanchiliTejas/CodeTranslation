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
    rep(i,0,n) cin>>a[i];
    deque<int> nib;
    nib.push_front(a[0]);
    rep(i,1,n){
        int x = a[i];
        int j = lower_bound(nib.begin(),nib.end(),x) - nib.begin();
        if (j==0){
            nib.push_front(x);
        }else{
            nib[j-1] = x;
        }
    }
    cout<<nib.size()<<endl;
}