#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, N) FOR(i, 0, N)
#define SZ(x) ((int)(x).size())
 
const int MAXN = 57, INF = 100000007;
 
int main()
{	
	int N, p;
	ll a[MAXN], K = 0;
	cin >> N;
	REP(i, N) cin >> a[i];
	while (true){
		p = 0;
		REP(i, N) if (a[i] > a[p]) p = i;
		if (a[p] < N) break;
		K += a[p]/N;
		REP(j, N) if (j != p) a[j] += a[p]/N;
		a[p] -= N*(a[p]/N);		
	}
	cout << K;
	//cout << endl; system("pause");//please
	return 0;
}//don't forget about const, please