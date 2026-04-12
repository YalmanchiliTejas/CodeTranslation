#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <utility>
#include <map>
#include <set>
#include <complex>
#include <numeric>

#include <time.h>
#include <float.h>

#define loop(i, n) for(i = 0; i < n; i++)
#define loop1(i, n) for(i = 1; i <= n; i++)
#define loop2(i, n, start) for(i = start; i <= n; i++)
#define loopIterators(it, vec) for(it = (vec).begin(); it != (vec).end(); it++)
#define loopRev(i, n) for(i = (n - 1); i >= 0; i--)
#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCases(t) cin >> t; while(t--)
#define PN(n) cout << (n)
#define PN1(n) cout << (n) << " "
#define PN2(a, b) cout << (a) << " " << (b) << " "
#define PNN1(n) cout << (n) << endl
#define PNN2(a, b) cout << (a) << " " << (b) << endl
#define PNN3(a, b, c) cout << (a) << " " << (b) << " " << (c) << endl
#define PrintArray(ar, n) for(i = 0; i < n; i++) cout << ar[i] << " "; cout << endl
#define PrintSet(ar, it) for(it = ar.begin(); it != ar.end(); it++) cout << *it << " "; cout << endl
#define PrintMap(map, it) for(it = map.begin(); it != map.end(); it++) PNN2(it -> first, it -> second)
#define sz(a) sizeof(a)
#define IN1(n) cin >> n
#define IN2(a, b) cin >> a >> b
#define IN3(a, b, c) cin >> a >> b >> c
#define ALL(s) s.begin(), s.end()
#define SWAP(a, b, c) c = a; a = b; b = c
#define STRSP(s) scanf("%[^\n]%*c", s)
#define ENTER PNN1("");
#define MOD7 1000000007
#define MOD9 10000009
#define MAX 100005
#define llPair std::pair<lli, lli>
#define iiPair std::pair<int , int>
#define ONLINE_JUDGE

typedef long long int lli;
typedef long int li;
typedef unsigned long long int ulli;
typedef long double ld;

using namespace std;

int main(void){
	FLASH

	#ifndef ONLINE_JUDGE
		freopen("input-stream.txt", "r", stdin);
    freopen("output-stream.txt", "w", stdout);
	#endif

	std::string str;
	std::string::iterator it;
	IN1(str);
	int a = 0, b = 0;

	loopIterators(it, str) if (*it == 'A') ++a; else ++b;

	PNN1(a == 3 || b == 3? "No": "Yes");

	#ifndef ONLINE_JUDGE
		fclose(stdin);
    fclose(stdout);
	#endif

	return 0;
}
