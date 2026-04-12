#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
int n,p[N];
vector<ii> x,y;	
vector<pair<int,ii> >E;
int get(int u){
	if(p[u]==u)return u;
	return p[u]=get(p[u]);
}
int main(){
	cin>>n;
	for(int a,b,i=0; i<n; ++i){
		scanf("%d%d",&a,&b);
		x.pb(ii(a,i));
		y.pb(ii(b,i));
		p[i]=i;
	}
	sort(all(x));
	sort(all(y));
	for(int i=0; i<n-1; ++i){
		int c=x[i+1].first-x[i].first;
		E.pb(make_pair(c,ii(x[i].second,x[i+1].second)));
	}
	for(int i=0; i<n-1; ++i){
		int c=y[i+1].first-y[i].first;
		E.pb(make_pair(c,ii(y[i].second,y[i+1].second)));
	}
	sort(all(E));
	ll ans=0;
	for(int i=0; i<E.size(); ++i){
		int c=E[i].first, a=E[i].second.first, b=E[i].second.second;
		if(get(a)!=get(b)){
			ans+=c;
			p[get(a)]=get(b);
		}
	}
	cout<<ans<<endl;
}


