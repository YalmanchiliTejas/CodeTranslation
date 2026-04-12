#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt","r",stdin);
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
void read(int &val) { int x = 0; int bz = 1; char c; for (c = getchar(); (c<'0' || c>'9') && c != '-'; c = getchar()); if (c == '-') { bz = -1; c = getchar(); }for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48; val = x * bz; }
const int INF = 0x3f3f3f3f;
const int maxn=1e6+7;
const int mod=1e9+7;
typedef long long LL;

int n,m;


int main(){
    int x;cin>>x;
    if(x>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}