#include <bits/stdc++.h>
#define PI acos(-1.0)
#define mem(a,b) memset((a),b,sizeof(a))
#define TS printf("!!!\n")
#define pb push_back
#define inf 1e9
//std::ios::sync_with_stdio(false);
using namespace std;
//priority_queue<int,vector<int>,greater<int>> que; get min
const double eps = 1.0e-10;
const double EPS = 1.0e-4;
typedef pair<int, int> pairint;
typedef long long ll;
typedef unsigned long long ull;
const int turn[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
//priority_queue<int, vector<int>, less<int>> que;
//next_permutation
ll mod = 3e7;
int main()
{
        ll N, K;
        cin >> N >> K;
        ll ans = 0;
        if (K == 0)
        {
                cout << N*N << endl;
                return 0;
        }
        for (ll i = K + 1; i <= N; i++)
        {
                ll time = N / i;
                if (N % i >= K)
                {
                        ans += N % i - K + 1;
                }
                ans += time * (i - K);
        }
        cout << ans << endl;
}
