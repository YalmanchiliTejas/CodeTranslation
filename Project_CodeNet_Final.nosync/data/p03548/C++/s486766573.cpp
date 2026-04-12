#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
	int i,j,k,n,m,l,f,x,y,z; string s;
	cin >> x >> y >> z;
	if(x%(y+z) < z) cout << x/(y+z) - 1 << endl;
	else cout << x/(y+z) << endl;
}	