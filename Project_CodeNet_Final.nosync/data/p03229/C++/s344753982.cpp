#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	VI A(N);
	REP(i, N) {
		cin >> A[i];
	}
	int fu1 = (N + 1) % 2, fu2 = (N - 1) / 2, pu1, pu2;
	if (N < 4) {
		pu2 = 0;
	}
	else {
		pu2 = N / 2 - 1;
	}
	if (N < 3) {
		pu1 = 1;
	}
	else {
		if (N % 2 == 1)
			pu1 = 2;
		else
			pu1 = 1;
	}
	rSORT(A);
	int ans = 0;
	int i = 0;
	while (pu2 > 0) {
		ans += A[i] * 2;
		pu2--;
		i++;
	}
	while (pu1 > 0) {
		ans += A[i];
		pu1--;
		i++;
	}
	while (fu1 > 0) {
		ans -= A[i];
		fu1--;
		i++;
	}
	while (fu2 > 0) {
		ans -= A[i] * 2;
		fu2--;
		i++;
	}
	int anss = 0;

	pu1 = (N + 1) % 2;
	pu2 = (N + 1) / 2 - 1;
	fu1 = N % 2 + 1;
	if (N == 1)fu1 = 1;

	if (N < 4) {
		fu2 = 0;
	}
	else {
		fu2 = (N - 2) / 2;
	}
	i = 0;
	while (pu2 > 0)
	{
		anss += A[i] * 2;
		pu2--;
		i++;
	}
	while (pu1 > 0){
		anss += A[i];
		i++;
		pu1--;
	}
	while (fu1 > 0) {
		anss -= A[i];
		i++;
		fu1--;
	}
	while (fu2 > 0) {
		anss -= A[i] * 2;
		i++; 
		fu2--;
	}
	//cout << pu1 << " " << pu2 << " " << fu1 << " " << fu2 << endl;

	cout << max(ans, anss) << endl;
	return 0;
}

