//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

const int inf = 1<<25;

ll dp[3005][3005];
ll arr[3005], n;

ll solve(int i, int j)
{
    if(i >= n || j < 0 || i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    ll ret = max(arr[i] - solve(i + 1, j), arr[j] - solve(i, j - 1));

    return dp[i][j] = ret;

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    ll res = solve(0, n - 1);

    cout<<res<<endl;

    return 0;
}
