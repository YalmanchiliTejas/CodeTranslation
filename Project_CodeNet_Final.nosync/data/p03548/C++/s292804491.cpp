#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
typedef long long ll;
const int INF=0x3f3f3f3f;
int d[8][2]={{-1,0},{0,-1},{0,1},{1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x-=z;
    printf("%d",x/(y+z));
    return 0;
}
