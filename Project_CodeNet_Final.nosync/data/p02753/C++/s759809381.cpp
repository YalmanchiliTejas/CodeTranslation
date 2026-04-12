#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string s; cin >> s;
    int count_a = 0, count_b = 0;
    rep(i,3) {
        char c = s[i];
    	if (s[i] == 'A') count_a++;
        else count_b++;
    }
    if (count_a == 3 || count_b == 3) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}