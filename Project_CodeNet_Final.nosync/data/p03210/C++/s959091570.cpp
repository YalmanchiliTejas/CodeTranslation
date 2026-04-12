/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (long long i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (long long i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1003
#define maxm 500005
#define pii pair <int,int>
#define Task ""
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,x,y,cnt[105];
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    //freopen(Task".inp", "r",stdin);
    //freopen(Task".out", "w",stdout);
    cin >> n;
    if (n == 3 || n == 5 || n == 7) cout << "YES";
    else cout << "NO";
    return 0;
}
