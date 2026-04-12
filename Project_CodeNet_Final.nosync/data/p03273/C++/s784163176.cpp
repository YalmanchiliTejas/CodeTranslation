#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;

int main(){
	int h,w; cin>>h>>w;
	char a[101][101];
	FOR(i,0,h)FOR(j,0,w)cin>>a[i][j];
	vector<int> hi,wi;
	FOR(i,0,h){
		int sum=0;
		FOR(j,0,w){
			sum+=(a[i][j]=='.'?0:1);
		}
		if(sum!=0) hi.PB(i);
	}
	FOR(j,0,w){
		int sum=0;
		FOR(i,0,h){
			sum+=(a[i][j]=='.'?0:1);
		}
		if(sum!=0) wi.PB(j);
	}
	FOR(i,0,hi.size()){
		FOR(j,0,wi.size()){
			cout<<a[hi[i]][wi[j]];
		}
		cout<<endl;
	}
}
