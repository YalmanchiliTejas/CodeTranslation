#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define endl '\n'
#define sz(x) (int) x.size()
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
const int maxn=1e4+5;
const int base=1e9+7;
int n,k;
char a[maxn];
int f[maxn][105][2];
void Input()
{
    cin >> (a+1);
    n=strlen(a+1);
    cin >> k;
}
int calc(int i, int remain, int isless)
{
    if (i>n) return remain==0;
    int &res=f[i][remain][isless];
    if (res!=-1) return res;
    res=0;
    FOR(digit,0,9)
        if (isless||digit<=a[i]-'0') {
            res+=calc(i+1,(remain+digit) mod k,isless|(digit<a[i]-'0'));
            if (res>=base) res-=base;
        }
    return res;
}
void Solve()
{
    fillchar(f,sizeof(f),255);
    cout << (base-1+calc(1,0,0)) mod base << endl;
}
int main()
{
    #ifdef meomeomeooooo
        freopen("input.txt","r",stdin);
        //freopen(".out","w",stdout);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
