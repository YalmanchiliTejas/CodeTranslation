#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n,k; cin >> n >> k;
    ll ans = 0;
    if(k==0){
      	cout << n * n << endl;
      	return 0;
    }
    for(int b=k+1;b<=n;b++){
        ll md = n%b;
        if(md<k){
            ans += (n/b)*(b-k);
        }else{
            ans += (n/b)*(b-k) + (md-k+1);
        }
    }
    cout << ans << endl;
}