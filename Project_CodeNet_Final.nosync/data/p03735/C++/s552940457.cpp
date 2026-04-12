#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;

int n;
ll ans;

pair<int,int> x[200010];
multiset<int> b,r;

void work()
{
	sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)
    {
        b.erase(b.find(x[i].f)),r.insert(x[i].f);
        r.erase(r.find(x[i].s)),b.insert(x[i].s);
        ans=min(ans,1ll*(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin()));
    }
    printf("%lld",ans);
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i].f,&x[i].s);
		if(x[i].f>x[i].s) swap(x[i].f,x[i].s);
		b.insert(x[i].f),r.insert(x[i].s);
	}
	ans=1ll*(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin());
}

int main()
{
    init();
    work();
    return 0;
}