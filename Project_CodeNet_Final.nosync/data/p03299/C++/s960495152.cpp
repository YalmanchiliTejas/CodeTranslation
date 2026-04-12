#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T;

vl A;

ll getv(ll i){
    if(i == -1)return 0;
    if(i == n)return 0;
    assert(i >= 0 && i < n);
    return A[i];
}

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

vl heights;
set<ll> S;

ll upto(ll i, ll j){
    if(j == 0){
        return (upp(2,A[i])-2+big)%big;
    }
    return (upp(2,A[i]-heights[j]+1)-2+big)%big;
}

ll horisontal(ll i, ll j){
    if(heights[j] >= A[i])return 0;
    ll d1 = A[i]-heights[j];
    ll d2 = A[i]-heights[j+1];
    return (upto(i,j)-upto(i,j+1)+big)%big;
}


unordered_map<ll,ll> M;

ll dp(ll i, ll horisont, bool vertical){
    if(i == n)return 1;
    ll h = 2ll*(i*ll(12345678911)+horisont) + vertical;
    if(M.find(h) != M.end())return M[h];

    ll ans = 0;
    if(A[i] == 0){
        return dp(i+1,0,1);
    }
    if(vertical){
        ans += 2*dp(i+1,A[i],1);
        if(A[i] > horisont){
            for(int c1 = 0; c1 < sz(heights); c1++){
                if(heights[c1] < horisont)continue;
                ans += horisontal(i,c1)*dp(i+1,heights[c1],0);
                ans %= big;
            }
        }
    }
    if(!vertical){
        if(horisont >= A[i]){
            ans = 2*dp(i+1,A[i],1);
        }
        else{
            ll d = max(A[i]-getv(i-1),0ll);
            ans = upp(2,d)*dp(i+1,horisont,0);
        }
    }

    ans %= big;
    M[h] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    ll ans = 1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        if(a == 1){
            a = 0;
            ans *= 2;
            ans %= big;
        }
        A.push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        d = max(A[c1] - max(getv(c1-1),getv(c1+1)),0ll);
        ans *= upp(2,d);
        ans %= big;
        A[c1] -= d;
    }
    heights.push_back(0);
    S.insert(0);
    for(int c1 = 0; c1 < n; c1++){
        if(S.find(A[c1]) == S.end()){
            S.insert(A[c1]);
            heights.push_back(A[c1]);
        }
    }
    sort(all(heights));
/*
    cerr << "h: " << horisontal(1,0) << " " << horisontal(1,1) << "\n";

    cout << ans << "\n";
    for(int c1 = 0; c1 < n; c1++){
        cout << A[c1] << " ";
    }cout << "\n";
    cerr << dp(5,0,1) << "  jk\n";
    */
    ans *= dp(0,0,1);
    cout << ans%big << "\n";


    return 0;
}
