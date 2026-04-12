//a
#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory>
#include <functional>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>

#define REP(i,b,n) for(int i=b;i<n;i++)
#define REPR(i,b,n) for(int i=n-1;i>=b;i--)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define NCLR(mat) memset(mat, -1, sizeof(mat))
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define EACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define BIT(n, b) ((n>>b) & 1)
#define PB push_back
#define MP make_pair

using namespace std;

static const double PI = acos(-1.0);
static const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	
	int n;
	int s[1000];
	
	while(cin>>n, n){
		
		for(int i=0; i<n; ++i){
			cin>>s[i];
		}
		
		sort(s, s+n);
		
		int sum=0;
		
		for(int i=1; i<n-1; ++i){
			sum+=s[i];
		}
		
		sum /=n-2;
		
		cout << sum << endl;
	}
	
	return 0;	
}