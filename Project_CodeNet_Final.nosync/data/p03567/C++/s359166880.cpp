#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,0,-1,1,0,0};
const ld PI=abs(acos(-1));
int n,m,a,b,c,d,e;
string s,w;

int main(){
	cin >> s;
	REP(i,0,s.size()-1){
		if(s[i]=='A' and s[i+1]=='C'){cout << "Yes" << endl; return 0;}
	}
	
	cout << "No" << endl;
	return 0;
}
