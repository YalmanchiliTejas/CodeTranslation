#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

int n, rev;
deque<int> b;

int main(){
	cin >> n;
	REP(i, 1, n){
		int x;
		cin >> x;
		if (!rev) b.push_back(x);
		else b.push_front(x);
		rev ^= 1;
	}
	if (!rev){
		while (!b.empty()) printf("%d ", b.front()), b.pop_front();
		puts("");
	}
	else{
		while (!b.empty()) printf("%d ", b.back()), b.pop_back();
		puts("");
	}
	return 0;
}