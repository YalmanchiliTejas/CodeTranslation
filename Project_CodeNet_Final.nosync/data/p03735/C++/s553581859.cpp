#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=200000+10;
struct dong{
    int id,v;
    friend bool operator <(dong a,dong b){
    	return a.v<b.v;
	}
} a[maxn*2];
int v[maxn*2];
int i,j,k,l,r,t,n,m,mx,mi,num;
ll ans;
int main(){
    scanf("%d",&n);
    fo(i,1,n){
		scanf("%d%d",&a[i].v,&a[i+n].v);
		if (a[i].v>a[i+n].v) swap(a[i].v,a[i+n].v);
	}
    fo(i,1,2*n) a[i].id=i,v[i]=a[i].v;
    mx=mi=v[1];
    fo(i,1,n){
        mx=max(mx,v[i+n]);
        mi=min(mi,v[i]);
    }
    l=v[1];r=v[1+n];
    fo(i,1,n){
        l=max(l,v[i]);
        r=min(r,v[i+n]);
    }
    ans=(ll)(l-mi)*(mx-r);
    sort(a+1,a+2*n+1);
    num=l;
    fo(i,1,2*n){
        if (a[i].id>n) break;
        num=max(num,v[a[i].id+n]);
        ans=min(ans,(ll)(mx-mi)*(num-a[i+1].v));
    }
    printf("%lld",ans);
}