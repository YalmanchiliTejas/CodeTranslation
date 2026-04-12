/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

void solve(int test_case) {
	int n;
	cin>>n;
	string s,sol="-1";
	cin>>s;
	bool hasAns = false;
	for(int j=0;j<4&&!hasAns;j++) {
		string ans(n,' ');
		if(j==0)ans[0]='W',ans[1]='W';
		else if(j==1)ans[0]='W',ans[1]='S';
		else if(j==2)ans[0]='S',ans[1]='W';
		else ans[0]='S',ans[1]='S';
		for(int i=1;i<n-1;i++) {
			bool equal = s[i]=='o';
			if(ans[i]=='W')equal=!equal;
			if(equal)ans[i+1]=ans[i-1];
			else ans[i+1]=(ans[i-1]=='W'?'S':'W');
		}
		bool nowAns = true;
		for(int i=0;i<n;i++) {
			bool equal = s[i]=='o';
			if(ans[i]=='W')equal=!equal;
			bool now = ans[(n+i-1)%n]==ans[(i+1)%n];
			if((!equal&&now)||(equal&&!now)){nowAns=false;break;}
		}
		if(nowAns) {
			hasAns = true;
			sol=ans;
		}
	}
	cout<<sol;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
