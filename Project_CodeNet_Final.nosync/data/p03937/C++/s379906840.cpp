#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 924844033  //1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
//#define dprintf(...) 
#define hash _hash
#define next _next
//#define dprintf(...) fprintf(outFile,__VA_ARGS__)
 
#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ull unsigned long long
#define ll long long
#define N 100005
 
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}
 
//FILE* outFile;
inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}


int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*(ll)a%mod;
        a=(ll)a*a%mod;b>>=1;
    }
    return ans;
}

char s[10][10];
int vis[10][10];
bool OK(int n,int m){
    if(s[0][0]!='#'||s[n-1][m-1]!='#')return 0;
    int p=0,q=0,x=0,y=0,cnt=n+m-2;vis[0][0]=1;
    while(cnt--){
        p=q=0;
        if(x<n-1&&s[x+1][y]=='#')p=1;
        if(y<m-1&&s[x][y+1]=='#')q=1;
        if(p&&q || p==0&&q==0)return 0;
        if(p)x++;else y++;
        vis[x][y]=1;
    }
    if(x!=n-1||y!=m-1)return 0;
    rep(i,0,n)rep(j,0,m)if(s[i][j]=='#'&&!vis[i][j])return 0;
    return 1;
}
int main(){
    //freopen("1.txt","w",stdout);
    //cout<<setprecision(3)<<fixed;
    int T,i,j,k,m=0,n;
    scanf("%d%d",&n,&m);
    rep(i,0,n)scanf("%s",s[i]);
    if(!OK(n,m))puts("Impossible");
    else puts("Possible");    
    return 0;
}