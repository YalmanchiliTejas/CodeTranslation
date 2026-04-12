#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))
//#define int long long int //dont forget to change int to signed

int main() {
	int N;
	scanf("%d", &N);
	int abc[26][50];
	SET_ZERO(abc);
	for (int i = 0; i < N; i++) {
		char str[51];
		scanf("%s", str);
		for (int  l = 0; str[l] != '\0'; l++) {
			unsigned t = str[l] - 'a';
			abc[t][i]++;
		}
	}

	string ans = "";
	for (int i = 0; i < 26; i++) {
		sort(&abc[i][0], &abc[i][0] + N);
		for (int j = 0; j < abc[i][0]; j++) {
			ans += (char)i + 'a';
		}
	}
	cout << ans << endl;
	return 0;
}
