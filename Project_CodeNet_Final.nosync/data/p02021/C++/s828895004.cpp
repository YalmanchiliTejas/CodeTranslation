#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define lP pair<ll,ll>
#define iP pair<int,int>

typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;

int N, A, s, MAX;

int main(){
	cin >> N >> s;
	MAX = s;
	for (int i = 2; i != N+1; ++i) {
		cin >> A;
		s += A;
		if (i*MAX > s) {
			MAX = s / i;
		}
	}
	cout << MAX << endl;
	return 0;
}

