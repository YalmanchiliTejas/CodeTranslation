#include <bits/stdc++.h>
using namespace std;

//Function Macros:
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define setpre(n) cout << fixed << setprecision(n)

//Type Definitions:
typedef long long ll;
typedef unsigned long long ull;

//Constants:
const int INF = 2e9;
const int MOD = 1e9 + 7;

//Global Variables:

//Prototype Declarations:
int gcd(int, int);

//================ Main Loop ================
int main()
{
    int n, ans = 1;
    cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
        if (i > 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (h[j] > h[i])
                {
                    break;
                }
                if (j == i - 1)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//===========================================

//Functions:
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}