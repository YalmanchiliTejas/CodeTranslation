#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

#define min(a, b) ((a) < (b))? (a):(b)
#define max(a, b) ((a) > (b))? (a):(b)
#define abs(a) ((a) < (0)? -(a):(a))
#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(typeof(n) i=(a); i<(n); i++)
#define pb push_back

int main() {
	int N; cin >> N;
	string s; cin >> s;
	for(string head: {"SS", "SW", "WS", "WW"}) {
	    string ans = head;
	    REP(i, 1, N+1) {
	        string tail = ans.substr(ans.size()-2, 2);
	        if(s[i%N]=='o') ans.pb((tail=="SS"||tail=="WW")? 'S':'W');
	        else ans.pb((tail=="SS"||tail=="WW")? 'W':'S');
	    }
	    if(ans.substr(N,2)==head) {cout << ans.substr(0, N) << endl; return 0;}
	}
	cout << "-1" << endl;
}
