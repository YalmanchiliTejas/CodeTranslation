#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;

void Main(){
    ll n, x, m; cin >> n >> x >> m;
    
    set<pair<ll, int>> st;
    vll data(m+5), sum(m+5);
    
    ll now = x;
    st.insert({now, 0});
    data[0] = now;
    sum[0] = 0;
    sum[1] = now;
    
    int s = -1, t = -1;
    rep3(i, 1, m+1){
        now *= now;
        now %= m;
        data[i] = now;
        sum[i+1] = sum[i] + now;
        Pll LB = *st.lower_bound({now, -1});
        if(LB.fi == now){
            s = LB.se;
            t = i;
            break;
        }
        st.insert({now, i});
    }
    
    if(s == -1){
        cout << sum[n] << endl;
        return;
    }
    
    int k = t - s;
    // cout << s << " " << t << " " << k << endl;
    /*
    for(auto [a, b] : st){
        cout << a << " " << b << endl;
    }
    //*/
    ll q = (n-s)/k;
    ll r = (n-s)%k;
    // cout << q << " " << r << endl;    
    
    ll tot = sum[s];
    // cout << tot << endl;
    tot += (sum[t] - sum[s]) * q;    
    // cout << tot << endl;
    tot += sum[s+r] - sum[s];
    cout << tot << endl;
    return;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}