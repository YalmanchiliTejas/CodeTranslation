#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v
#define NUM(x,v) (POSU(x,v)-POSL(x,v))
const ll INF=1e9+7;
const ll N = 8;
ll h,w,did=0,n=0;
bool ok;
bool f=false;
char a[N][N];

void dfs(ll y,ll x){
	did++;
	if(x==w-1&&y==h-2){
		did++;
		ok=true;
		f=true;
		return;
	}else if(x==w-2&&y==h-1){
		did++;
		ok=true;
		f=true;
		return;
	}
	if(x+1<w)if(a[y][x+1]=='#')dfs(y,x+1);
	if(f)return;
	if(y+1<h)if(a[y+1][x]=='#')dfs(y+1,x);
	if(f)return;
	if(x+1<w&&a[y][x+1]!='#'&&y+1<h&&a[y+1][x]!='#'){
		ok=false;
	}
	did--;
}



int main(){
	cin>>h>>w;
	FOR(i,0,h){
		FOR(j,0,w){
			cin>>a[i][j];
			if(a[i][j]=='#')n++;
		}
	}
	dfs(0ll,0ll);
	if(ok&&(n==did)){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}