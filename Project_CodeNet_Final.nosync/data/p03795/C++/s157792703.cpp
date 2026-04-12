#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //

int main(void)
{
    int N;
    cin >> N;

    int discount = 200 * (N / 15);
    int ans = N * 800 - discount;
    cout << ans << endl;
    return (0);
}