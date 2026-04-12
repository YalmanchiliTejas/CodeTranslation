#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<cctype>
#include<iomanip>

using namespace std;
typedef long long int ll;typedef pair<int, int> P;
const long long mod = 1e9 + 7;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(a) (a).begin(),(a).end()
#define allg(a) (a).begin(),(a).end(),greater<>()
#define SUM(a) accumulate((a).begin(),(a).end(),0)
const double PI = 3.14159265359;

int main(void) {
	ll a, b, c; cin >> a >> b >> c;
	a -= c;
	b += c;
	cout << a / b << endl;




	return 0;
}