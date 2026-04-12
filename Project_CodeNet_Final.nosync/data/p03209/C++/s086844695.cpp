#include <bits/stdc++.h> 
using namespace std;
///////////////////////////////////////////
const long long int INF = INT32_MAX;
const long long int Mod = 1000000007;
const long long int mod = 100000;//10^5
using ll = long long int; //long long int は64bit
using ci = const int; using vi = vector<int>; using Vi = vector<long long int>; using pii = pair<int,int>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(int i=0;i<N;i++)
#define np nullptr
template<class T>bool chmax(T &former, const T &b) { if (former<=b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define fill(x,num) memset(x,num,sizeof(x));
typedef vector<vector<ll> > matrix;
//       cin.tie(0);ios::sync_with_stdio(false);
void cinit(){cin.tie(0);ios::sync_with_stdio(false);}
//////////////////////////^^ *Emile ^^^//////////////////////////////////////////////////////

ll mai(ll x){
	ll ans = 4;
	rep(i,x)ans*=2;
	return ans-3;
}

ll n,x;
ll memo[51]={0};

ll cal(ll lv,ll nu){
	if(nu == mai(lv)){
		if(memo[lv]!=0){return memo[lv];}
		else return memo[lv] = cal(lv-1,mai(lv-1))*2 + 1;
	}else{
		nu-=1;
		if(nu<=0)return 0;
		if(mai(lv-1)<nu){
			return cal(lv-1,mai(lv-1)) + cal(lv-1,nu-mai(lv-1)-1) + 1;
		}else{
			return cal(lv-1,nu);
		}
	}
}

int main(){
	cin>>n>>x;
	memo[0]=1;
	cout<<cal(n,x)<<endl;
	return 0;
}