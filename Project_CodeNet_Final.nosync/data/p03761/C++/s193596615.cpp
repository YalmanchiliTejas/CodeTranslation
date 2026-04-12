#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
#define INF 999999999

unsigned GetDigit(unsigned num){
    unsigned digit = 0;
    while(num != 0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n; cin >> n;
	vector<string> s(n);
	REP(i, n){ cin >> s[i]; }
	vector<int> cnt(26, INF);
	REP(i, n){
		REP(j, 26){
			cnt[j] = min(cnt[j], (int) count(s[i].begin(), s[i].end(), 'a'+j));
		}
	}
	REP(i, 26){
		REP(j, cnt[i]){
			cout << char('a'+i);
		}
	}
	cout << endl;
}
