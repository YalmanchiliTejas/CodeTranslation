#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+5,inf=2e9;

multiset<int>R,B;
ll Rmx=-inf,Rmn=inf,Bmx=-inf,Bmn=inf,ans;

int read() {
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}

struct bags {
    int v1,v2;

    bags() {}

    bags(int _v1,int _v2) {
        v1=_v1,v2=_v2;
    }

    bool operator<(const bags &a)const {
        return v1<a.v1;
    }
}p[maxn];

ll calc() {
    return 1ll*(*R.rbegin()-*R.begin())*(*B.rbegin()-*B.begin());
}

int main() {
    int n=read();
    for(int i=1;i<=n;i++) {
        int x=read(),y=read();
        if(x>y)swap(x,y);
        p[i]=bags(x,y);
        R.insert(x),B.insert(y);
    }
    sort(p+1,p+n+1);
    ans=calc();
    for(int i=1;i<=n;i++) {
        int x=p[i].v1,y=p[i].v2;
        R.erase(R.find(x)),B.insert(x);
        B.erase(B.find(y)),R.insert(y);
        ans=min(ans,calc());
    }
    printf("%lld\n",ans);
    return 0;
}