//https://blog.csdn.net/hesorchen
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define endl "\n"
#define lowbit(a) (a & (-a))
#define INF 0x3f3f3f3f
#define MAX 1010
#define mod 1000000007
#define PI 3.1415926

int p[100100];
int t[100010], ct = 1;
int f(int l, int r, int k)
{
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (t[mid] >= k)
            l = mid + 1;
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
int main()
{
    // fill(t, t + 100000, -1);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        int temp = f(1, ct - 1, p[i]);
        if (temp == -1)
        {
            // // t[ct++] = p[i];
            // for (int j = ct; j >= 2; j--)
            //     t[j] = t[j - 1];
            t[ct++] = p[i];
            // ct++;

            // sort(t + 1, t + ct);
        }
        else
            t[temp] = p[i];
    }
    cout << ct - 1 << endl;
    return 0;
}