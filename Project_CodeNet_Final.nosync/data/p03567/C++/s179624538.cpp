#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 200005;
const ll mod = 10;
const ll INF = 0x3f3f3f3f;
const double eps = 1e-9;

char s[maxn];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='C')
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}