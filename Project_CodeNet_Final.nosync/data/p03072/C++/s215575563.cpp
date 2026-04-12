#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

uintmax_t combination(unsigned int n, unsigned int r)
{
    if (r * 2 > n)
        r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor = 1;
    for (unsigned int i = 1; i <= r; ++i)
    {
        dividend *= (n - i + 1);
        divisor *= i;
    }
    return dividend / divisor;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<int> H(N);
    int m = 0;
    int ans = 1;
    cin >> H[0];
    m = H[0];
    for (int i = 1; i < N; i++)
    {
        cin >> H[i];
        if(m <=H[i]){
            ans++;
            m = H[i];
        }
    }
    cout << ans << endl;
}
