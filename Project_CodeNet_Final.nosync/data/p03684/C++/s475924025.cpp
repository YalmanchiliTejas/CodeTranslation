#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pli> vpli;

#define I_Love_Hashimoto_Kanna main
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file freopen("I_Love_Hashimoto_Kanna.out","w",stdout);
#define RE cout<<233<<endl;
#define Tone(Kanna) cout<<Kanna<<endl;
#define Tall(Hashimoto,Love) for(int Kanna=0;Kanna<n;Kanna++)cout<<Hashimoto[Kanna]<<(Kanna==Love-1?"\n":" ");
#define FOR(Love,Hashimoto,Kanna) for(int Love=Hashimoto;Love<Kanna;Love++)
#define REV(Kanna) reverse(Kanna.begin(),Kanna.end());
#define SORT(Kanna) sort(Kanna.begin(),Kanna.end());
#define inf (int)1e9
#define linf (ll)1e18
#define mod (inf+7)

int n;
pair<pii,int> a[111111];
vector<pair<ll,pii > > edge;
int f[111111];
int F(int a){
	return f[a]==a?a:f[a]=F(f[a]);
}


int I_Love_Hashimoto_Kanna() {
  fastio;
  FOR(i,0,111111)f[i]=i;
  cin>>n;
  FOR(i,0,n){
  	cin>>a[i].first.first>>a[i].first.second;
  	a[i].second=i;
	}
	FOR(tot,0,2){
	  sort(a,a+n);
	  FOR(i,0,n-1){
      edge.push_back({(ll)min(abs(a[i].first.first-a[i+1].first.first),abs(a[i].first.second-a[i+1].first.second)),{a[i].second,a[i+1].second}});
		  swap(a[i].first.first,a[i].first.second);
	  }
	  swap(a[n-1].first.first,a[n-1].first.second);
	}
	SORT(edge);
	ll ans=0;
	FOR(i,0,edge.size()){
		int a,b,c;
		c=edge[i].first;
		a=edge[i].second.first;
		b=edge[i].second.second;
		a=F(a);
		b=F(b);
		if(a==b){
			continue;
		}
		ans+=c;
		f[a]=b;
	}
	cout<<ans<<endl;
	
  return 0;
}

