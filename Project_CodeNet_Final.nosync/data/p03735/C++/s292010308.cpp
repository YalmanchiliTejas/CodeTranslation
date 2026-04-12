#include<bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=2e5+10;
int n;ll res;P d[MAXN];
multiset<int> a,b;
ll cal(){return 1ll*(*a.rbegin()-*a.begin())*(*b.rbegin()-*b.begin());}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&d[i].X,&d[i].Y);
        if(d[i].X>d[i].Y) swap(d[i].X,d[i].Y);
        a.insert(d[i].X);b.insert(d[i].Y);
    }
    sort(d+1,d+n+1);
    res=cal();//minmax在不同侧
    for(int i=1;i<=n-1;i++)
    //minmax在同一侧
    //考虑每次交换后下界单调不减
    {
        a.erase(a.find(d[i].X));b.insert(d[i].X);
        b.erase(b.find(d[i].Y));a.insert(d[i].Y);
        res=min(res,cal());
    }
    printf("%lld",res);
    return 0;
}