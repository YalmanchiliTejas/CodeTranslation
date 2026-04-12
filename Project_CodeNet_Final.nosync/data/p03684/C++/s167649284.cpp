#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct node{
    int x,y,id;
}a[100010];
struct edge{
    int a,b,w;
}e[200010];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
bool cmpx(node a,node b){
    return a.x<b.x;
}
bool cmpy(node a,node b){
    return a.y<b.y;
}
int pre[200010];
int find(int x){
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main(){
//    freopen("B-small-attempt1.in","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a,a+n,cmpx);
    int cnt=0;
    for(int i=1;i<n;i++,cnt++){
        e[cnt].a=a[i-1].id;
        e[cnt].b=a[i].id;
        e[cnt].w=a[i].x-a[i-1].x;
    }
    sort(a,a+n,cmpy);
    for(int i=1;i<n;i++,cnt++){
        e[cnt].a=a[i-1].id;
        e[cnt].b=a[i].id;
        e[cnt].w=a[i].y-a[i-1].y;
    }
    for(int i=0;i<n;i++)
        pre[i]=i;
    sort(e,e+cnt,cmp);
    LL ans=0;
    int tot=0;
    for(int i=0;i<cnt&&tot+1<n;i++){
        int u=e[i].a,v=e[i].b;
        int fa=find(u),fb=find(v);
        if(fa!=fb){
            pre[fa]=fb;
            ans+=e[i].w;
            tot++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
/*
*/
