#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cerr << #x << "=" << x << endl

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<bool> bv;

int main(void) {

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int sum_1 = a*x+b*y;
    int sum_2 = a*max(x-y, 0)+c*2*y;
    int sum_3 = b*max(y-x, 0)+c*2*x;

    cout << min(min(sum_1, sum_2), sum_3) << endl;
}
