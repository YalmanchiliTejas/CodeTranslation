//RohitKaushal
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define MOD 1000000007
#define INF 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y) 
#define mem(a,val) memset(a,val,sizeof(a))
#define f first
#define s second

ll ncr(ll n,ll r){
	if(r==0){
		return 1;
	}
	else if( r==1){
		return n;
	}
	else if( r==2){
		return n*(n-1)/2;
	}
	else if( r==3){
		return n*(n-1)*(n-2)/6;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin>>s;
	ll k;
	cin>>k;
	ll n = s.size();
	ll ans=0;
	ll i;

	if(n<k){
		cout<<0;
		return 0;
	}
	for (i = 0; i < n && k; ++i)
	{
		if(s[i]!='0'){
			ans += pow(9,k)*ncr(n-i-1,k);
			if(s[i]-'0' - 1)
				ans += (s[i]-'0' - 1)*pow(9,k-1)*ncr(n-i-1,k-1);
		k--;
		}
	}
	if(n-i>0 || s[n-1]!='0') ans++;
	cout<<ans;


	return 0;
}