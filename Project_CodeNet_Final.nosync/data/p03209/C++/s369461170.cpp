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

const int N=55;
ll tam[N],lel[N];

void pcal(){
	tam[0]=1;
	FER(i,1,51)tam[i]=2*tam[i-1]+3;
	lel[0]=0;
	FER(i,1,51)lel[i]=2*lel[i-1]+2;
}

ll solve(ll n,ll x){
	//trace(n);
	//trace(x);
	if(x==0)return 0;
	if(n==0)return 0;
	if(x==tam[n])return lel[n];
	if(x<=tam[n-1]+1)return 1+solve(n-1,x-1);
	return 1+solve(n-1,tam[n-1])+solve(n-1,x-2-tam[n-1]);
}

int main(){	
	fastio;
	ll n,x;cin>>n>>x;
	if(n==0){
		cout<<1<<endl;
		return 0;
	}
	pcal();
	cout<<x-solve(n,x)<<endl;
	return 0;
}
