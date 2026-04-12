#include <bits/stdc++.h>
#define PI acos(-1.0)
#define mem(a,b) memset((a),b,sizeof(a))
#define TS printf("!!!\n")
#define pb push_back
#define inf 0x3f3f3f3f
//std::ios::sync_with_stdio(false);
using namespace std;
//priority_queue<int,vector<int>,greater<int>> que; get min
const double eps = 1.0e-10;
const double EPS = 1.0e-4;
typedef pair<int, int> pairint;
typedef long long ll;
typedef unsigned long long ull;
//const int maxn = 3e5 + 10;
const int turn[4][2] = {{0, 1}, { 1, 0}, { 0, -1}, { -1, 0}};
//priority_queue<int, vector<int>, less<int>> que;
//next_permutation
int num[200005];
int t[200005];
int a[200005];
map<int, int> mp;
map<int, int> mpb;
int pop = 0;
int n;
int len;
int lowbit(int x)
{
        return x & (-x); //右起第一个1的位置为第k个 返回值则为2^(k-1)
}
void update(int x, int p) //更新第x 的值
{
        while (x <= len)
        {
                t[x] += p;
                x += lowbit(x); //不断找到自己的祖先 更新值
        }
        return;
}
int sum(int k)//前k个数的和
{
        int ans = 0;
        while (k > 0)
        {
                ans += t[k];
                k -= lowbit(k);
        }
        return ans;
}
int ask(int l, int r) //求l-r区间和
{
        return sum(r) - sum(l - 1);
}
int main()
{
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                cin >> num[i];
                a[i] = num[i];
        }
        sort(num + 1, num + 1 + n);
        len = unique(num + 1, num + 1 + n) - num - 1;
        for (int i = 1; i <= len; i++)
        {
                mp[num[i]] = ++pop;
                mpb[pop] = num[i];
        }
        //cout<<len<<endl;
        int aim = (n - 1) / 2 + 1;
        for (int i = 1; i <= n; i++)
        {
                update(mp[a[i]], 1);
        }
        for (int i = 1; i <= n; i++)
        {
                update(mp[a[i]], -1);
                int l = 0, r = 2 * len;
                int mid;
                while (l < r - 1)
                {
                        mid = (l + r) >> 1;
                        if (ask(1, mid) >= aim)
                        {
                                r = mid;
                        }
                        else
                        {
                                l = mid;
                        }
                }
                cout << mpb[r] << endl;
                update(mp[a[i]], 1);
        }
}
