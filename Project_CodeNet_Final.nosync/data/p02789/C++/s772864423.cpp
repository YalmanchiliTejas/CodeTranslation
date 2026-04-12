#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <climits>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <tuple>

#define INF INT_MAX>>1 
#define SIZE 100010
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep2(i, from, to) for(int i=(from); i<(int)(to); i++)
#define all(obj) (obj).begin(), (obj).end()
#define lpair pair<ll, ll>
#define vint vector<ll>
#define vinput(name) for(int i=0; i<(int)(name.size()); i++) cin >> name[i];
#define voutput(name) for(int i=0; i<(int)(name.size()); i++) cout << name[i] << endl;
typedef long long ll;

using namespace std;

ll ans = 0;

int main(void){
	int a, b; cin >> a >> b;
	if(a == b) cout << "Yes";
	else cout << "No";
	return 0;
}