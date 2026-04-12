#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include <map>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include"time.h"
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define dump(x)  cerr << #x << " = " << (x) << endl
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
const int INF = (1 << 30);

//毎回変える場所
#define N_MAX 200


//問題文のとおり
string str;
int main() {
	cin >> str;
	bool flag = false;
	REP(i, str.size() - 1) {
		if (str[i] == 'A' && str[i + 1] == 'C')flag = true;
	}
	cout << (flag ? "Yes" : "No") << endl;
	cin >> str;
	return 0;
}