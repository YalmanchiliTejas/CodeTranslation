#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define fi first
#define se second

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

//区間加算と区間最小値
/*
verified by
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3982764#1
*/
struct StarrySkyTree{
private:
    int n;
    vector<ll> node,lazy;
    vector<bool> lazyFlag;
 
public:
    StarrySkyTree(){
        int sz=200050;
        n=1;
		while(n < sz) n*=2;
        node.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
        lazyFlag.resize(2*n-1,false);
    }
    void lazyEvaluate(int k,int l,int r){
        if(lazyFlag[k]){
            node[k]+=lazy[k];//一様更新なのでminの値もそれ足すだけでok
            if(r-l>1) {
                lazy[k*2+1]+=lazy[k];
                lazy[k*2+2]+=lazy[k];
                lazyFlag[k*2+1]=lazyFlag[k*2+2]=true;
            }
            lazyFlag[k]=false;
            lazy[k]=0;
        }
    }
    void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
        if(r<0) r=n;
        lazyEvaluate(k,l,r);
        if(b<=l || r<=a) return ;
        if(a<=l && r<=b) {
            lazy[k]+=x;
            lazyFlag[k]=true;
            lazyEvaluate(k,l,r);
        }
        else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=max(node[2*k+1],node[2*k+2]);
        }
    }

    ll find(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0) r=n;
      lazyEvaluate(k,l,r);
      if(r<=a || b<=l) return 0;
      if(a<=l && r<=b) return node[k];
      else{
        ll vl=find(a,b,2*k+1,l,(l+r)/2);
        ll vr=find(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
      }
	}
};

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	StarrySkyTree seg;
	map<int,vector<Pi>> mp;
	rep(i,m){
		int l,r,a;
		cin>>l>>r>>a;
		mp[r].push_back({l,a});
	}
	FOR(i,1,n+1){
		ll sum=0;
		ll ne=seg.find(0,i);
		for(auto now:mp[i]){
			int l=now.fi,a=now.se;
			seg.add(l,i,a);
			sum+=a;
		}
		ne+=sum;
		seg.add(i,i+1,ne);
	}
	cout<<seg.find(0,n+1)<<endl;
	/*
	dp[i][j]:i番目まで見てそれ以前にある、最後の1がj番目である時の最大スコア
	dp[i][j]=dp[i-1][j]+\sum_{k for lk<=j and rk=i} ak (j<i)
	dp[i][i]=max_j(dp[i-1][j])+\sum_k{k for rk=i} ak
	となる
	seg木で管理して行けばO(n+m)になる
	*/
}