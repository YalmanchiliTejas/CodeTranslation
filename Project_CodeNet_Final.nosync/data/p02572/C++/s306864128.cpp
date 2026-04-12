#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=0;i<j;i++)
#define FORN(i,j,k) for(int i=j;i<k;i++)
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define vpii vector<pii >
#define all(a) a.begin(),a.end()
using namespace std;
const ll M=1e9+7;
int n;
ll a[200005];
ll ans=0;
ll cnt[200005]={0};

int main(void){
	cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	FORN(i,1,n+1)cnt[i]=(cnt[i-1]+a[i-1])%M;
	REP(i,n){
		ans=(ans+(a[i]%M*cnt[i]%M+M)%M)%M;
//		cout<<i<<':'<<a[i]*(cnt[n]-cnt[i+1])<<endl;
	}
	cout<<ans;
	return 0;
}