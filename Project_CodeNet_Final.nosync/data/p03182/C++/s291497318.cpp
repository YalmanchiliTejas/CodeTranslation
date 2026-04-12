#if 1

#include <bits/stdc++.h>
using namespace std;
int n,m;
long long t[800005],t2[800005];
vector <pair <int,int> > a[200005];

void up(int x,int l,int r,int rl,int rr,long long c)
{
    if(rl <= l&&r <= rr)
    {
        t[x] += c;
        t2[x] += c;
        return;
    }
	int mid = (l+r) >> 1;
	if(rl <= mid) up(x*2,l,mid,rl,rr,c);;
	if(rr > mid) up(x*2+1,mid+1,r,rl,rr,c);
	t[x] = max(t[x*2],t[x*2+1])+t2[x];
}

int main()
{
    int x,y,z;
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[y].push_back({x,z});
    }
    for(int i = 1;i <= n;i++)
    {
        up(1,1,n,i,i,t[1]);
        for(int j = 0;j < a[i].size();j++)
        {
            up(1,1,n,a[i][j].first,i,a[i][j].second);
        }
    }
    printf("%lld",max((long long)0,t[1]));
}

#endif // 1
