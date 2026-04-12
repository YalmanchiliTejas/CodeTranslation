#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<ll>st;
    ll ans = 0;
    int n;
    cin >> n;
    f1 (n) {
        ll x;
        cin >> x;
        st.insert(x);
    }
    while (1) {
        ll mx = *st.rbegin();
        multiset<ll>newst;
        if (mx < n) break;
        st.erase(st.find(mx));
        ll t = (mx - mx % n) / n;
        for (auto &i : st) {
            newst.insert(i + t);
        }
        newst.insert(mx % n);
        st = newst;
        ans += t;
    }
    cout << ans << '\n';
}