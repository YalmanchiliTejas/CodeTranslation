// https://github.com/atcoder-live/library
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,(e))
#define irp(i,s,e) for(int i=(s);i>(e);--i)
#define irpz(i,s) irp(i,(s),-1)
template<class T> T in(){T x;cin>>x;return x;}
// long long a = in<long long>();
template<class T> void inarr(int s,int e,T &v){rp(i,s,e)cin>>v[i];}
// inarr<vi>(0,N,V);
#define NMAX 100000
int N,M;
string S, T;
vi V(NMAX);

string solve(){
	return N==M?"Yes":"No";
}

int main(){
	// N = in<int>();
	// S = in<string>();
	cin>>N;
	cin>>M;
	// cin>>S;
	// rpz(i,N){
	// 	cin>>V[i];
	// }
	ote(solve());
}
