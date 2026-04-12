#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int h,w;
string s[10];

int main(){
	cin >> h >> w;
	REP(i,0,h) cin >> s[i];
	
	int c=0;
	REP(i,0,h) REP(j,0,w) c+=(s[i][j]=='#');
	
	cout << (c==h+w-1?"Possible":"Impossible") << endl;
	return 0;
}

