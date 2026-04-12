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
#define MOD 1000000007
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll a[200001];
	FOR(i,n){
		cin>>a[i];
		if(i>0) a[i]+=a[i-1];
	}
	ll sum=0;
	FOR(i,n){
		int k=(i==0?a[i]:a[i]-a[i-1]);
		sum+=(k*((a[n-1]-a[i])%MOD))%MOD;
		sum%=MOD;
	}
	cout<<sum%MOD;
}