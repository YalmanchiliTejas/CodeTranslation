#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;

const string YES = "Yes";
const string NO = "No";

int main() {
    int X;
    cin >> X;
    if (X >= 30) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
    return 0;
}
