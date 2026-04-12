#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;

ll n;
ll a[300000];
ll f[300000][2];
bool flag[300000][2];

int get_status(int now, int n)
{
    if (((n-now+1)%2)==0)
        return 0;
    else
        return 1;
}

ll dp(int i, int status)
{
    if (i>n) return 0;
    if (i==n && status==0) return 0;
    if (flag[i][status]) return f[i][status];
    flag[i][status]=1;

    if (status==1)
    {
        f[i][status] = a[i] + dp(i+2, 1);
    }else
    {
        int remain = get_status(i, n);
        if (remain == 0)
        {
            f[i][status] = max(a[i]+ dp(i+2, 0), dp(i+1, 1));
        }else
        {
            f[i][status] = max(a[i] + dp(i+2, 0), dp(i+1,0));
        }
    }

    return f[i][status];

}

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];

    cout << dp(1, 0) << endl;
    return 0;
}

