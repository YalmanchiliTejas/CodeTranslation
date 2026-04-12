#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) cerr << #x << "=" << static_cast<bitset<16> >(x) << endl;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

const int INF = 10000000;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
using namespace std;
typedef long long  ll;

/** Problem1147 : ICPC Score Totalizer Software **/
int main()
{
	int N;
	vector<int> s;
	
	while (cin>>N, N) {
		int sum=0;
		s.clear();
		rep(i, N) {
			int n;
			cin >> n;
			s.push_back(n);
			sum+=n;
		}
		
		int m = *min_element(s.begin(), s.end());
		int M = *max_element(s.begin(), s.end());
		
		sum -= m; sum -= M;
		
		cout << sum/(N-2) << endl;
		
	}
}