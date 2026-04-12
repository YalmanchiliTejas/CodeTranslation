#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define inf 1000000007
typedef long long ll;
using namespace std;
typedef pair<ll,ll> P;
priority_queue<P,vector<P>,greater<P> >Q;
vector<ll> v;
int main(){
	int n;
	ll left=inf,right=0;
	ll Min_rng=inf,Max_rng=0;
	ll Min_b=inf;
	cin>>n;
	lol(i,n){
		ll a,b;cin>>a>>b;
		if(a>b)swap(a,b);
		left=min(left,a);
		right=max(right,a);
		Min_rng=min(Min_rng,a);
		Max_rng=max(Max_rng,b);
		Min_b=min(Min_b,b);
		Q.push(make_pair(a,b));
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll ans=(right-Min_rng)*(Max_rng-Min_b);
	//cout<<"#"<<left<<" "<<right<<" "<<Min_rng<<" "<<Max_rng<<endl;
	while(!Q.empty()){
		ll a=Q.top().first,b=Q.top().second;
		Q.pop();
		int it=lower_bound(v.begin(),v.end(),a)-v.begin();
		it++;
		if(it==n)break;
		if(a>Min_b)break;
		left=min(v[it],Min_b);
		right=max(right,b);
		ll tmp=(right-left)*(Max_rng-Min_rng);
		//cout<<"$"<<" "<<right<<" "<<left<<" "<<tmp<<endl;
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}
