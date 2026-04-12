#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define mod (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void print(bool f)
{
    cout << (f ? "Yes" : "No") << endl;
}

void Print(bool f)
{
    cout << (f ? "YES" : "NO") << endl;
}

vll sou(51), meet(51);

ll where(ll num, ll x)
{
    //cout << num << " " << x << endl;
    if (num == 0)
    {
        //cout << "L0" << endl;
        return 1;
    }
    if (x == 0)
    {
        //cout << "LE" << endl;
        return 0;
    }
    if (x == sou[num] - 1)
    {
        //cout << "RE" << endl;
        return meet[num - 1] * 2 + 1;
    }
    if (x == sou[num] / 2)
    {
        //cout << "C" << endl;
        return meet[num - 1] + 1;
    }
    if (x < sou[num] / 2)
    {
        //cout << "L" << endl;
        return where(num - 1, x - 1);
    }
    if (x > sou[num] / 2)
    {
        //cout << "R" << endl;
        return meet[num - 1] + 1 + where(num - 1, x - sou[num] / 2 - 1);
    }
}

int main(void)
{
    ll n, x;
    cin >> n >> x;

    sou[0] = 1, meet[0] = 1;
    rep(i, 0, n)
    {
        sou[i + 1] = sou[i] * 2 + 3;
        meet[i + 1] = meet[i] * 2 + 1;
    }
    cout << where(n, x - 1) << endl;
}