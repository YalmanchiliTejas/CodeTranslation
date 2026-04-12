#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
	int i,j,k,n,m,l,f,x,y,z; string s;
	int h, w;
	string t[105];
	cin >> h >> w;
	rep(i, h) cin >> t[i];

	int a[105] ={0}, b[105]={0};
	rep(i, h){
		rep(j,w){
			if(t[i][j] == '#') continue;
			a[i]++;
		}
	}

	rep(i, w){
		rep(j, h){
			if(t[j][i] == '#') continue;
			b[i]++;
		}
	}

	rep(i, h){
		if(a[i] == w) continue;
		rep(j, w){
			if(b[j] == h) continue;
			cout << t[i][j];
		}
		cout << endl;
	}
}