#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main(void){
	// string s;	cin >> s;
	int N; cin >> N;
	int H[N];
	rep(i,N)	cin >> H[i];
	int ans = 1;
	reps(i,N-1)	{
		rep(j,i)	{
			if (H[j] > H[i])	break;
			if (j==i-1)	ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
