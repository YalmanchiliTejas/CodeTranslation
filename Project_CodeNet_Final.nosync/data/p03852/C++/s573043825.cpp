#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin,(a).rend()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c; cin >> c;
	char lo[] = { 'a','i', 'u', 'e', 'o' };
	bool elf = false;
	rep(i, 5) if (c == lo[i]) elf = true;
	puts(elf ? "vowel" : "consonant");
	return 0;
}