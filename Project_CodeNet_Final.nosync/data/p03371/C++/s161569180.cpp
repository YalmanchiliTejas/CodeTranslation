#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu

const ll INF=1e9+7;
const ll N = 10002;
ll a,b,c,ans=INF,x,y;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>x>>y;
	for(ll i=0;i<200001;i+=2){
		ll w=i*c;
		ll aa=x-i/2;
		ll bb=y-i/2;
		if(aa>0)w+=aa*a;
		if(bb>0)w+=bb*b;
		ans=min(ans,w);
	}
	cout<<ans<<endl;
	return 0;
}