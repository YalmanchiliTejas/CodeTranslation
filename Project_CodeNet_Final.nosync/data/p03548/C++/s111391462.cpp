#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>

#define PI acos(-1)
#define INF 0x3f3f3f3f
#define SCD(a) scanf("%d",&a)
#define SCL(a) scanf("%lld", &a)
#define SCLL(a,b) scanf("%lld%lld", &a, &b)
#define SCDD(a,b) scanf("%d%d",&a,&b)
#define SCF(a) scanf("%lf",&a)
#define PTD(a) printf("%d", a)
#define PTL(a) printf("%lld", a)
#define PTLE(a) printf("%lld\n", a)
#define PTDE(a) printf("%d\n",a)
#define MST(a,b) memset(a, b, sizeof(a))
#define FOR(a,b,c) for(int a=b; a<c; a++)
#define pb push_back
#define ll long long

using namespace std;
const int D = 20;
const int L = 1e5 + D;
int n, m, T;
int ans;
int a[L];
vector<int> v;

void solve()
{
    int i,  t;
    for(i=0; i<n; i++){
        SCD(t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    ans = 0;
    for(i=1; i<v.size(); i++)
        a[i] = v[i] - v[i-1] - 1 ;
    for(i=2; i<v.size(); i++){
        ans += max(a[i], a[i]);

    }

    PTDE(ans);
}


int main()
{
    int i ,j ,t;
    int x, y, z;
    ans = 0;
    SCDD(x, y);
    SCD(z);
    i = 1;
    ans = (x - z)/(y + z);
    PTDE(ans);
    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

/*


*/
