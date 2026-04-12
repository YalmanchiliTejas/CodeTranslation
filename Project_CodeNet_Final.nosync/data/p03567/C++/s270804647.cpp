#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<ll, int> P;

string s;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>s;
	if(s.find("AC")!=-1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
