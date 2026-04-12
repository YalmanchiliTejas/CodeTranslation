#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (ll i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e5+5;
ll arr[N];
ll mark[N];

void solve(){
	ll n,x,m;
	cin>>n>>x>>m;
	if(n==1){
		cout<<x<<endl;
		return;
	}
	ll i=2;
	arr[1]=x;
	mark[x]=1;
	ll sum=x;
	vll rem;
	while(i<=n){
		x=(x*x)%m;
		if(x==0){
			cout<<sum<<endl;
			return;
		}
		if(mark[x]!=0){
			for(int j=mark[x];j<i;j++){
				rem.pb(arr[j]);
			}
			i--;
			break;
		}
		sum+=x;
		arr[i]=x;
		mark[x]=i;
		i++;
		if(i>n){
			cout<<sum<<endl;
			return;
		}

	}
	// cout<<i<<endl;
	i=n-i;
	ll temp=0;
	ll sz=rem.size();
	fr(j,0,sz){
		temp+=rem[j];
	}
	ll y=i/(sz);
	sum=sum+(y*temp);
	i=i%(sz);
	fr(j,0,i){
		sum+=rem[j];
	}
	cout<<sum<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}