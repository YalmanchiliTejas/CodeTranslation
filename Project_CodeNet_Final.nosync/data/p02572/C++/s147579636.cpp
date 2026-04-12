/******
	~site:    atcoder.jp
	~user:    Turkhuu
	~problem: AtCoder Beginner Contest 177 - C (abc177_c)
** **/

#include<bits/stdc++.h>

#define FFOR(i,s,e,k) for(int i=s;(k==1?i<=e:i>=e);i+=k)
#define FOR(i,n) FFOR(i,0,n-1,1)
#define FORR(i,s,e) FFOR(i,s,e,1)
#define ll long long
#define PQ priority_queue
#define pb push_back
#define ppb pop_back()
#define pp push
#define MIN(v) *min_element(v.begin(),v.end())
#define MAX(v) *max_element(v.begin(),v.end())
#define SORT(v) sort(v.begin(),v.end())
#define TROS(v) sort(v.rbegin(),v.rend())
#define CNT(v,x) count(v.begin(),v.end(),x)

using namespace std;

const ll MOD=1000000007;

ll a[200001],s[200001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	ll sum=0;
	for(int i=n;i>=2;i--){
		sum+=(a[i]*(s[i-1]%MOD))%MOD;
		sum%=MOD;
	}
	cout<<sum;
}