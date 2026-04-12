//file_name:ABC54_C.cpp
#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

    // int scan
    /*
    int x;
    scanf("%d",&x);
    int y;
    scanf("%d",&y);
    int z;
    scanf("%d",&z);

    // matrix scan
    /*
    ll a[n] = {};
    rep(i,n){
        scanf("%lld",&a[i]);
    }
    */

    // string scan
    /*
    string s;
    cin >> s;
    */


int main() {
    int n;
    scanf("%d",&n);
    int m;
    cin >> m;
    int v[n][n];
    rep(i,n){
        rep(j,n){
            v[i][j] = 0;
        }
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }


    int ans = 0;

    int flag[7];

    for(flag[0]=1;flag[0]<n;flag[0]++){
        for(flag[1]=1;flag[1]<n;flag[1]++){
            for(flag[2]=1;flag[2]<n;flag[2]++){
                for(flag[3]=1;flag[3]<n;flag[3]++){
                    for(flag[4]=1;flag[4]<n;flag[4]++){
                        for(flag[5]=1;flag[5]<n;flag[5]++){
                            for(flag[6]=1;flag[6]<n;flag[6]++){
                                int f = 0;
                                rep(i,n-1){
                                    f += pow(2,flag[i]);
                                }
                                if(f!=pow(2,n)-2)continue;
                                int ff = 0;
                                rep(i,n-1){
                                    if(i==0){
                                        if(v[0][flag[0]]==0){
                                            ff = 1;
                                            break;
                                        }
                                    }else{
                                        if(v[flag[i-1]][flag[i]]==0){
                                            ff = 1;
                                            break;
                                        }
                                    }
                                }
                                if(ff==0)ans++;
                            }
                        }
                    }
                }
            }
        }
    }

    ans /= pow(n-1,8-n);



    cout << ans << endl;
    return 0;
}

