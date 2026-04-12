#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


Int s, t, p, q, m, y;

int main(){
    cin >> s >> t >> p >> q >> m >> y;
    cout << (t ^ s ^ y) << endl;
    return 0;
}

