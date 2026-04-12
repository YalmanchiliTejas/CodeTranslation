#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

ll comb(ll n, ll k)
{
    __int128 ans = 1;
    srep(i,n-k+1,n+1){
        ans *= i;
    }
    srep(i,1,k+1){
        ans /= i;
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    int val = 0;
    srep(i,1,471){
        if(comb(i+7,8) > K){
            K -= comb(i+6,8);
            val = i-1;
            break;
        }
        if(i == 470){
            K -= comb(i+7,8);
            val = i;
            break;
        }
    }
    vector<int> ad(val,0);
    for(int i = val; i >= 1; i--){
        ll hoge = comb(i+6,7);
        if(K >= hoge){
            ad[val-i] += K / hoge;
            K -= K / hoge * hoge;
        }
    }
    rep(i,val){
        rep(j,ad[i]){
            cout << 'F';
        }
        cout << "FESTIVAL";
    }
    cout << "\n";
    return 0;
}