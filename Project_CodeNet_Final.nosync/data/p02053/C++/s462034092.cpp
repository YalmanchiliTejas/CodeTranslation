#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void vprint(vector<ll> A){
    ll L = A.size();
    FOR(i, 0, L){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
}

struct Point{
    ll x, y;
    Point(ll _x, ll _y){
        x = _x;
        y = _y;
    }
};

ll dist(Point a, Point b){
    ll ans = abs(a.x - b.x) + abs(a.y - b.y);
    return ans;
}

ll L[1050];
ll R[1050];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll H, W;
    cin >> H >> W;

    FOR(i, 0, 1050){
        L[i] = -1;
        R[i] = -1;
    }

    FOR(i, 0, H){
        string s; cin >> s;
        FOR(j, 0, W){
            if(s[j]=='B'){
                L[i] = j; break;
            }
        }
        for(int j=W-1; j>=0; j--){
            if(s[j]=='B'){
                R[i] = j; break;
            }
        }
    }

    // pn(L[0]);
    // pn(L[1]);
    // pn(L[2]);
    // pn(L[3]);

    ll ma = 0;
    FOR(h, 0, H){
        FOR(u, 0, H){
            if(L[h]==-1) continue;
            if(L[u]==-1) continue;
            ll d0 = abs(h-u) + abs(L[h]-L[u]); chmax(ma, d0);
            ll d1 = abs(h-u) + abs(L[h]-R[u]); chmax(ma, d1);
            ll d2 = abs(h-u) + abs(R[h]-L[u]); chmax(ma, d2);
            ll d3 = abs(h-u) + abs(R[h]-R[u]); chmax(ma, d3);
        }
    }
    p(ma);
    return 0;
}
