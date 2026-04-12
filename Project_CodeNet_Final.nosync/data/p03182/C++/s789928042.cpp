//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

template<typename T,T(F_dd)(T,T),T(F_dl)(T,T),T(F_ll)(T,T)>
//dat-dat dat-lazy lazy-lazy min,add,addなどを入れる
struct Lazysegtree{
    int sz,ex;
    T ini_d,ini_l;//default値
    vector<T> dat,laz;
    vector<bool> need;

    Lazysegtree(int n,T _ini_d,T _ini_l) : Lazysegtree(vector<T>(n,_ini_d),_ini_d,_ini_l){}
    Lazysegtree(vector<T> init,T _ini_d, T _ini_l) : ini_d(_ini_d),ini_l(_ini_l){
        int n=(int)(init.size());
        ex=1;
        while((1<<ex) < n)ex++;
        sz=(1<<ex);//最下層のノード数になる
        
        dat=vector<T>(2*sz-1,ini_d);
        laz=vector<T>(2*sz-1,ini_l);
        need=vector<bool>(2*sz-1,false);
        for (int i = 0; i < n; i++) dat[sz + i -1] = init[i];//最下層以外のノード数はsz-1
        for (int i = sz-2; i >= 0; i--) {
            update(i);
        }//上層のノードの初期化
    }

    void update(int k){dat[k]=F_dd(dat[2*k+1],dat[2*k+2]);}//上層ノードの更新

    void seg_upd(int k,T x){//区間ノードに対する更新
        dat[k] = F_dl(dat[k],x);
        laz[k] = F_ll(laz[k],x);
        need[k]=true;
    }

    void eval(int k){//子の区間に伝播させる
        if(!need[k])return;

        seg_upd(2*k+1,laz[k]);
        seg_upd(2*k+2,laz[k]);
        laz[k]=ini_l;
        need[k]=false;
    }

    //区間[a,b)に対する取得クエリ [l,r)はノード番号kに対応する区間
    T get_q(int a,int b,int l,int r,int k){
        if(b<=l || r<=a) return -LINF;
        if(a<=l && r<=b) return dat[k];
        eval(k);//ノードを見たので遅延を一段階伝播させておく
        return F_dd(get_q(a,b,l,(l+r)/2,2*k+1),get_q(a,b,(l+r)/2,r,2*k+2));
    }
    T get_q(int a,int b){return get_q(a,b,0,sz,0);}


    //区間[a,b)に対する更新クエリ
    void up_q(int a,int b,T x,int l,int r,int k){
        if(b<=l || r<=a) return;
        if(a<=l && r<=b){
            seg_upd(k,x);
            return;
        }

        //子ノードを見る必要がある場合
        eval(k);
        up_q(a,b,x,l,(l+r)/2,2*k+1);
        up_q(a,b,x,(l+r)/2,r,2*k+2);
        update(k);//更新終了後、親も更新
    }
    void up_q(int a,int b,T x){up_q(a,b,x,0,sz,0);}
};//初期値の設定に注意（完全二分木にするために拡張した部分の初期値もini_dになる）
//区間minmaxクエリに対しては拡張したノードの初期値をよしなに設定する必要あり


ll my_max(ll a,ll b){return max(a,b);}
ll my_add(ll a,ll b){return a+b;}

ll dp[200010]={};

signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,m;cin>>n>>m;
  priority_queue<PL,V<PL>,greater<PL>> q;
  priority_queue<tuple<ll,ll,ll>,V<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> qe;

  rep(i,0,m){
    ll l,r,x;cin>>l>>r>>x;
    q.push({l,x});
    qe.push(mt(r,l,-x));
  }

  Lazysegtree<ll,my_max,my_add,my_add> seg(200010,-LINF,0);
  ll cost=0;
  seg.up_q(0,1,LINF);
  rep(i,1,200010){
    seg.up_q(i,i+1,LINF);

    while(q.size() && q.top().fs==i){
      seg.up_q(0,i,q.top().sc);

      cost+=q.top().sc;
      q.pop();
    }
    while(qe.size() && get<0>(qe.top())==i-1){
      seg.up_q(0,get<1>(qe.top()),get<2>(qe.top()));
      cost+=get<2>(qe.top());
      qe.pop();
    }

    dp[i]=max(seg.get_q(0,i),cost);
    seg.up_q(i,i+1,dp[i]);


  }

  ll ans=0;
  rep(i,0,200001)chmax(ans,dp[i]);
  cout<<ans<<ENDL;
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?