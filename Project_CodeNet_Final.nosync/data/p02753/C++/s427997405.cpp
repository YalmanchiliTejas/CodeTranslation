//****************************//
/**********  main *************/
//****************************//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000


int main() {

	std::cin.tie(0);

	string s ;
	cin >> s ;

	(s[0]==s[1] && s[1]==s[2]) ? (cout << "No") : (cout << "Yes") << endl;

    return 0;
}

