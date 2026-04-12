#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

const ll longinf=1LL<<60;

struct LazySegmentTree{
private:
   int n;
   vector<ll> node,lazy;
public:
   LazySegmentTree(int sz,ll init=0){
      n=1;
      while(n<sz)n*=2;
      node.resize(2*n-1,init);
      lazy.resize(2*n-1,0);
   }
 
   void eval(int k,int l,int r){
      if(lazy[k]!=0)node[k]+=lazy[k];
      if(r-l>1){
          lazy[2*k+1]+=lazy[k];
          lazy[2*k+2]+=lazy[k];
      }
      lazy[k]=0;
   }
      //[a,b)にxを加算
   void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
       if(r<0)r=n;
       eval(k,l,r);
       if(r<=a||b<=l)return;
       if(a<=l&&r<=b){
          lazy[k]+=x;
          eval(k,l,r);
       }
       else {
          add(a,b,x,2*k+1,l,(l+r)/2);
          add(a,b,x,2*k+2,(l+r)/2,r);
          node[k]=max(node[2*k+1],node[2*k+2]);
        }
   }
   //[a,b)でのmaxを返す
   ll get(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0)r=n;
      eval(k,l,r);
      if(r<=a||b<=l)return 0;
      if(a<=l&&r<=b)return node[k];
      ll xl=get(a,b,2*k+1,l,(l+r)/2);
      ll xr=get(a,b,2*k+2,(l+r)/2,r);
      return max(xl,xr);
   }
};

// 終点でソートして考える

// dp[r] := rまで考慮して、rの位置を１とする時の最大スコア
// dp[r] は max(dp[0], dp[1], .... , dp[r-1]) + (rを1にすることによるスコア変化)
// である。

// dp[0] ~ dp[r-1]はrを見る時に更新されるが、最終的には正しい値になるので問題ない

int main() {
    int N, M;
	cin >> N >> M;

	vector<P_ii> R[N];
	ll sum = 0;
	REP(i, M){
		int l, r, a;
		cin >> l >> r >> a;
		R[r-1].push_back({l-1, a});
		sum += a;
	}
    
	LazySegmentTree sg(N+1, 0);

	REP(i, N){
		ll now = sg.get(0, i);
		sg.add(i, i + 1, now);
		for(auto s : R[i]){
			sg.add(s.first, i + 1, s.second);
		}
	}
	cout << sg.get(0, N) << endl;

    return 0;
}