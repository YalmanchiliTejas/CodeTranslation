#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int d[10][10];
int main(){
	rep(i,10)rep(j,10)d[i][j] = INF;
	int v,e;
	cin>>v>>e;
	rep(i,e){
		int a,b;
		cin>>a>>b;
		a--,b--;
		d[a][b] = d[b][a] = 1;
	}
	
	vector<int> w(v);
	rep(i,v)w[i] = i;
	sort(all(w));
	int c=0;
	do{
		bool f = true;
		if(w[0]!=0)continue;
		rep(i,v-1){
			if(d[w[i]][w[i+1]]!=1)f=false;
		}
		if(f)c++;
	}while(next_permutation(all(w)));
	cout<<c<<endl;
}