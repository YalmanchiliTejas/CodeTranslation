#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define Vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<ll,int> Pli;
typedef pair<string,string> Pss;
const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main() {
	int n;
	ll a,s=0;
	vector<Pli> v;
	v.push_back(Pli(0,0));
	cin>>n;
	rep(i,n){
		cin>>a;
		s+=a;
		v.push_back(Pli(s,i+1));
	}
	sort(v.begin(),v.end());
//	rep(i,n+1)cout<<v[i].first<<" "<<v[i].second<<endl;
	int res=0;
	int k=0;
	rep(i,n){
		if(v[i].first==v[i+1].first){
			res=max(res,v[i+1].second-k);
		}else{
			k=v[i+1].second;
		}
	}
	cout<<res<<endl;
	return 0;
}

