#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    int tempX = X;
    int tempY = Y;
    // if (A + B > C * 2)
    while (tempX > 0 && tempY > 0)
    {
        ans1 += C * 2;
        tempX--;
        tempY--;
    }
    while (tempX > 0)
    {
        ans1 += A;
        tempX--;
    }
    while (tempY > 0)
    {
        ans1 += B;
        tempY--;
    }

    tempX = X;
    tempY = Y;
    while (tempX > 0 || tempY > 0)
    {
        ans2 += C * 2;
        tempX--;
        tempY--;
    }

    // else
    tempX = X;
    tempY = Y;
    while (tempX > 0)
    {
        ans3 += A;
        tempX--;
    }
    while (tempY > 0)
    {
        ans3 += B;
        tempY--;
    }
    // printf("ans1 = %d, ans2 = %d, ans3 = %d\n", ans1, ans2, ans3);
    int ans = min(ans1, min(ans2, ans3));
    cout << ans << endl;
    return (0);
}