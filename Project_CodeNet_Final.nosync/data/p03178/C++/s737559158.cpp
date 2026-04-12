// dile a la jardinera que traigo flores

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define sz(x) int(x.size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define IFR(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


const int N=105;
const ll mod=1e9+7;
ll dp[N*N];
ll pc[N*N][N];
ll d;
string s;
ll ans;

inline void precal(){
	pc[0][0]=1;
	FER(tam,1,sz(s)+1)FER(j,0,d)FER(c,0,10){
		int id=((j-c)%d+d)%d;
		//pc[tam][j]=(pc[tam][j]+pc[tam-1][(j-c+d)%d])%mod;
		//if(tam<sz(s)&&c!=0&&j==0)ans=(ans+pc[tam-1][(j-c+d)%d])%mod;
		pc[tam][j]=(pc[tam][j]+pc[tam-1][id])%mod;
		if(tam<sz(s)&&c!=0&&j==0)ans=(ans+pc[tam-1][id])%mod;
	}
}

inline void solve(){
	ll acum=0;
	//trace(ans);
	IFR(tam,sz(s),1){
		ll id=sz(s)-tam;
		ll cur=s[id]-'0';
		FER(dig,tam==sz(s),cur){
			ll idd=(d-(acum+dig)%d)%d;
			dp[tam]=(dp[tam]+pc[tam-1][idd])%mod;
		}
		ans=(ans+dp[tam])%mod;
		acum=(acum+cur)%d;
	}
	ll sum=0;
	FER(i,0,sz(s))sum=(sum+(s[i]-'0'))%d;
	if(sum==0)ans=(ans+1)%mod;
	cout<<ans<<endl;
}


int main(){	
	fastio;
	cin>>s>>d;
	ans=0;
	precal();
	solve();

	return 0;
}
