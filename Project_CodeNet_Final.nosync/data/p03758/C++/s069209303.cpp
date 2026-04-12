#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unordered_set<ll> uset;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=0;i<=n;i++)
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("unroll-loops")
#pragma gcc target("avx2,see4")
int n;
bool thedge(ll a,ll b){//頂点aと頂点bの間に辺があるか
	string s="";
	rep(i,n)s+="0";
	s[a]=s[b]='1';
	cout<<"? "<<s<<"\n"<<flush;
	ll res;
	cin>>res;
	return res==1;
}
int main(){
	cin>>n;
	vector<P> ans;
	rep(i,n)for(int j=i+1;j<n;j++){
		/*string s;
		rep(k,n)s+="0";
		s[i]=s[j]='1';
		cout<<"? "<<s<<"\n"<<flush;
		ll res;
		cin>>res;
		if(res==1)ans.push_back(make_pair(i,j));*/
		if(thedge(i,j))ans.push_back(make_pair(i,j));
	}
	cout<<"!";
	for(auto e:ans){
		cout<<" ("<<e.first<<","<<e.second<<")";
	}
	cout<<"\n"<<flush;
}
