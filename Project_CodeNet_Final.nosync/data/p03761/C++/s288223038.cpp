#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;

int findSumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

vector<string> field;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<string> S(N);
    string ans;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    ll MI = 999999999;

    ll count = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        MI = 99999999;
        for (int i = 0; i < N; i++)
        {
            count = 0;
            for (int j = 0; j < S[i].size();j++)
            {
                if (S[i][j] == c)
                {
                    count++;
                }
            }
            MI = min(MI, count);
            if(MI == 0){
                break;
            }
        }
        for (int i = 0; i < MI;i++)
        {
            cout << c;
        }
    }
}