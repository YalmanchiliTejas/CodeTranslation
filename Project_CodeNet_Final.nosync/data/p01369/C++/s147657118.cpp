#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>

#define REP(i,b,n) for(int i=b;i<n;i++)
#define REPR(i,b,n) for(int i=n-1;i>=b;i--)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define NCLR(mat) memset(mat, -1, sizeof(mat))
#define EACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define BIT(n, b) ((n>>b) & 1)
#define PI acos(-1.0)

using namespace std;

static const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> paii;

string hand = "qwertasdfgzxcvb";

int main(){
	
	string str;
	
	while(cin >> str, str[0]!='#'){
		
		int cnt = 0;
		
		for(int i=0; i<str.size()-1; ++i){
			if( count(hand.begin(), hand.end(), str[i]) ^  count(hand.begin(), hand.end(), str[i+1])  )
				cnt++;
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}