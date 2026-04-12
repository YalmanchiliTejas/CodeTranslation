#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<cassert>
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
#define M 210
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
bool thedge_set(set<ll> S,ll x){//独立集合Sのいずれかと頂点xの間に辺があるか
	S.insert(x);
	string s="";
	rep(i,n)s+="0";
	for(auto t:S)s[t]='1';
	cout<<"? "<<s<<"\n"<<flush;
	ll res;
	cin>>res;
	return res>=1;
}

vector<ll> FANS_A,FANS_B;//FANS_A[i]とFANS_B[i]の間に辺がある
void dfs(ll x,set<ll> S){//xとSの間の辺を探す(一つはある）
	if(S.size()==1){
		FANS_A.push_back(x);
		FANS_B.push_back(*S.begin());
		return;
	}
	set<ll> L,R;
	bool flag=0;
	for(auto s:S){
		if(flag)L.insert(s);
		else R.insert(s);
		flag=flag^1;
	}
	if(thedge_set(L,x))dfs(x,L);
	if(thedge_set(R,x))dfs(x,R);
}
int main(){
	cin>>n;
	vector<ll> v[M];//v[d]:=0を根として深さdの頂点のidの集合
	{//2000~4500回でv[]を求める
		v[0].push_back(0);
		set<ll> cand;//まだ決まっていないもの
		for(int i=1;i<n;i++)cand.insert(i);
		for(ll d=0;d<M;d++){
			if(cand.size()==0)break;
			set<ll> cur;
			for(auto x:v[d])cur.insert(x);
			for(auto x:cand){
				if(thedge_set(cur,x)){
					v[d+1].push_back(x);
				}
			}
			for(auto x:v[d+1])cand.erase(x);
		}
	}
	{//dとd+1の間の辺を求める
		for(ll d=0;d<M;d++){
			if(v[d+1].size()==0)break;
			set<ll> A,B;
			for(auto x:v[d])A.insert(x);
			for(auto x:v[d+1])B.insert(x);
			if(A>B)swap(A,B);
			//|A|<=|B|、Aの要素に対して、辺がある方を探す
			/*for(auto x:A){
				dfs(x,B);
			}*/
			for(auto x:A)for(auto y:B){
				if(thedge(x,y)){
					FANS_A.push_back(x);
					FANS_B.push_back(y);
				}
			}
		}
	}
	/*if(n-1!=FANS_A.size()){
		ll x=0,y=0;
		while(1){
			if(x%2==0&&y%2==1)break;
			x++,y++;
		}
		cout<<x<<endl;
	}*/
	cout<<"!";
	for(int i=0;i<n-1;i++){
		cout<<" ("<<FANS_A[i]<<","<<FANS_B[i]<<")";
	}
	cout<<"\n"<<flush;
}
