#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int n, k;


int count(int b){

    if (b <= k) return 0;
    if (k == 0) return n;
    int ans = 0;
    ans = ((b-k)*(n/b)) + max(0,((n%b)-k+1));
    return ans;
}


int main()
{
    cin >> n >> k;

    ll ans = 0;
    rep1(b, n){
        ans += (ll)count(b);
        //cout << ans << endl;
    }
    cout << ans << endl;
}

