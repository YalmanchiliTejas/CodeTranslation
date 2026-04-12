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
	int a,b;
	cin>>a>>b;
	vector<vector<char>> arr(a,vector<char>(b));
	vi rows(a),cols(b);
	REP(i,0,a-1) {
		REP(j,0,b-1) {
			char c;
			cin>>c;
			arr[i][j]=c;
			if(c=='.'){cols[j]++;rows[i]++;}
		}
	}
	REP(i,0,a-1) {
		if(rows[i]==b)continue;
		REP(j,0,b-1) {
			if(cols[j]==a)continue;
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
	
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
