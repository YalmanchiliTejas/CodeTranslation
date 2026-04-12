#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <cmath>

#define FOR(i, f, n) for(int (i) = (f); (i) < (n); (i)++)
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (n); (i)--)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define step(i, f, n, a) for(int (i) = (f); (i) < (n); (i)+=a)
#define rstep(i, f, n, a) for(int (i) = (f); (i) >= (n); (i)-=a)
#define p(...) printf(__VA_ARGS__); cout << endl;
#define gets(x) x; cin >> x;
#define puts(x) x; cout << x << endl;
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](const a, const b){ return c ;}
#define key(t, x, compare) [](const t& a, const t& b){ return a x compare b x ;}

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(){
	int n;
	gets(n)
	puts( (n*800) - ((n/15)*200) )
}
