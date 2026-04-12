#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main(){
    ll n;
    cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    ll ans = 0;
    for(int c = 0; c < n; c++){
        ll score = 0;
        set<ll> st;
        for(int k = 0; k < n; k++){
            ll a = n-1 -k*c;
            ll b = a-c;
            if(a<=0 || b<=0){break;}
            if(st.count(k*c)==1){break;}
            score += s[k*c];
            st.insert(k*c);
            if(st.count(n-1-k*c)==1){break;}
            score += s[n-1-k*c];
            st.insert(n-1-k*c);
            ans = max(ans, score);
        }
    }

    cout << ans << endl;

    return 0;
}
