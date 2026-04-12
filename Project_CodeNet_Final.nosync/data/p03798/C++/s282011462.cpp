#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define SZ(x) ((int) (x).size())
typedef long long ll;

bool solve(string s, string &ans) {
    int len = s.length();
	char t = ans[0];
	rep(i,1,len) {
		if(s[i]=='o') {
			if(ans[i]=='S' && ans[i-1]=='S') ans[(i+1)%len] = 'S';
			else if(ans[i]=='S' && ans[i-1]=='W') ans[(i+1)%len] = 'W';
			else if(ans[i]=='W' && ans[i-1]=='S') ans[(i+1)%len] = 'W';
			else ans[(i+1)%len] = 'S';
		} else {
			if(ans[i]=='S' && ans[i-1]=='S') ans[(i+1)%len] = 'W';
			else if(ans[i]=='S' && ans[i-1]=='W') ans[(i+1)%len] = 'S';
			else if(ans[i]=='W' && ans[i-1]=='S') ans[(i+1)%len] = 'S';
			else ans[(i+1)%len] = 'W';
		}
	}
	if(t != ans[0]) return false;
	if(s[0]=='o') {
        if(ans[0]=='S') return ans[1] == ans[len-1];
        else return ans[1] != ans[len-1];
	} else {
        if(ans[0]=='S') return ans[1] != ans[len-1];
        else return ans[1] == ans[len-1];
	}
}

int main() {
    int n;
    string s;
    while(cin >> n >> s) {
        vector<string> vs = {"SS", "SW", "WS", "WW"};
        bool flag = false;
        rep(i,0,4) {
            string ans(s.length(), ' ');
			ans[0] = vs[i][0];
			ans[1] = vs[i][1];
            if(solve(s, ans)) {
                cout << ans << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}
