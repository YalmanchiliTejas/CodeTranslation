#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define nl cout<<"\n"
#define endl '\n'
#define pb push_back
#define se second
#define fi first
#define int long long 
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define For(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,n) for(int i=a;i<n;i++)
#define pie =3.14159265358979323846264338327950;
const int mod= 1e9+7;


void solve(){
	fio;
	int n;
	cin>>n;
	int ar[n];
	For(i,n) cin>>ar[i];
	int suf[n];
	suf[n-1]=ar[n-1];
	for(int i=n-2;i>=0;i--){
		suf[i]= suf[i+1]+ar[i];
		suf[i]%=mod;
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		ans+= ar[i]*suf[i+1];
		ans%=mod;
	}
	cout<<ans<<endl;
}

int32_t main(){
	fio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){ 
		//cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
