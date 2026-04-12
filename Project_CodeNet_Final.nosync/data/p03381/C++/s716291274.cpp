#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 2e5+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=2.718281828459045235360287471352662;
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
struct data
{
    int pos;
    int num;
}a[maxn];
int ans[maxn];
bool cmp(data a,data b)
{
    return a.num<b.num;
}
int main()
{
    ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        a[i].pos=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i<=n/2)
            ans[a[i].pos]=a[n/2+1].num;
        else
            ans[a[i].pos]=a[n/2].num;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
