#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const int INF = 1e9;

int main(void){

	string S; cin >> S;
	set<char> st;
	REP(i,3){
		st.insert(S[i]);
	}
	
	if(st.size() == 1) cout << "No" << endl;
	else cout << "Yes" << endl;


	return 0;

}
