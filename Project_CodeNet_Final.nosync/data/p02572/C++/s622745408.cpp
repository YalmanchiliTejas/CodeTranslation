//ÃˆÃ“Ã£ Ã‡Ã¡Ã¡Ã¥ Ã¦Ã¡Ã‡ ÃÃ¦Ã¡ Ã¦Ã¡Ã‡ ÃžÃ¦Ã‰ Ã…Ã¡Ã‡ ÃˆÃ‡Ã¡Ã¡Ã¥
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define ins insert
#define be begin
#define en end
#define fast ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
using namespace std;
const int INF=1e9;
//ll a,b;
ll a[202020],b[202020];
vector<ll>v;
pair<ll,ll>p;
map<string,int>mp;
//map<string,int>::iterator it;
set<ll>st;
set<ll>::iterator it;
string s,t;
ll q,n,m,k,z,x,y,d,sum,cnt,mx=0,ans;
ll cum[2020202];
ll M=1e9+7;
int main(){
	fast;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cum[i]=i>0? cum[i-1]+a[i] : a[i];
	}
	for(int i=0;i<n;i++){
		sum=(cum[n-1]-cum[i]);
		ans=((ans%M)+(((a[i]%M)*(sum%M))%M))%M;

	}
	cout<<ans;
}