#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define VSORT(v) sort(v.begin(), v.end())
#define SORT(v, n) sort(v, v+n)
#define VREV(v,n) reverse(v,v+n)
#define REV(v,n) reverse(v,v+n)
#define vi vector<int>
#define pf push_front
#define pb push_back
#define P pair<int,int>
#define Pll pair<ll,ll>

template<class T, size_t N> size_t countof(const T (&array)[N]) { return N; }
template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<"\n";}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}

void mprint(auto *matrix,auto N){
	REP(i,N) cout<<matrix[i]<<(i!=N-1?' ':'\n');
	return;
}

const double EPS =1e-9;
const int INF =2e+9;
const ll INFL =9e+18;
const long MOD =1e+9+7;
#define PI 3.14159265258979

#define iP pair<int,P>
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

inline int in(){int x; cin>>x; return x;}

int main(void){
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	ll sum=X*A+B*Y;
	chmin(sum,(X*C*2)+B*max(0ll,Y-X));
	chmin(sum,A*max(0ll,X-Y)+(Y*C*2));
	print(sum);
	return 0;
}
