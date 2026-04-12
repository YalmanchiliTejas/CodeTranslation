#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define p(x) cout << x << endl;
#define el cout << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int num = n / 15;

    int ans = (800 * n) - (200 * num);
    p(ans);
}
