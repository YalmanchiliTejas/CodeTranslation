#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SREP(i, s) for(int i = 0; i < (s.size()); i++)
#define SORT(v, n) sort(v, v+n);
#define GSORT(v, n) sort(v, v+n, greater<int>());
#define VSORT(v) sort(v.begin(),v.end());
#define VGSORT(v) sort(v.begin(),v.end(),greater<int>());
#define REV(a) reverse(begin(a),end(a));
 
ll gcd(ll x, ll y){
	if(x<y) swap(x,y);
	if(y==0) return x;
	return gcd(y,x%y);
}
 
ll lcm(ll x, ll y){
	return (x*y/gcd(x,y));
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
////////////////////////////////////////////
	int h,w;
	cin >> h >> w;
	string a[h];
	REP(i,h) cin >> a[i];
	bool bh[h],bw[w];
	memset(bh,false,sizeof(bh));
	memset(bw,false,sizeof(bw));
	REP(i,h)REP(j,w){
		if(a[i][j]=='#'){
			bh[i]=1;
			bw[j]=1;
		}
	}
	REP(i,h){
		if(bh[i]){
			REP(j,w){
				if(bw[j]) cout << a[i][j];
			}
			cout << endl;
		}
	}
/////////////////////////////////////////////
}
