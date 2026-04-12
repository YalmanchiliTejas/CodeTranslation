#include <bits/stdc++.h>
#define long long long
#define ull unsigned long long
#define up(i,a,b) for (int i=a; i<=b; i++)
#define down(i,a,b) for (int i=a; i>=b; i--)
#define endl '\n'
#define pb push_back
#define X first
#define Y second
#define II pair<int, int>
#define III pair<int, pair<int, int> >
#define V vector
#define debug(X) cerr<< #X << " = " <<X << endl
#define debug2(X,Y) cerr<< #X << " = " <<X << ","<<#Y<<" = "<<Y<<endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar

using namespace std;

inline void read(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x){

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }
const int N= (int) 1e5+10;
int n;
V<int> a[N];
int match[N];

void input()
{
    cin>>n;
    up(i,1,n-1)
    {
        int u,v; cin>>u>>v;
        a[u].pb(v); a[v].pb(u);
    }
}
void dfs(int u,int p)
{
    for (auto v: a[u])
		if (v!=p)
		{
			dfs(v,u);
		}
    if (u!=1 and !match[u] and !match[p] ) match[u]= match[p]= 1;
}
void solve()
{
    dfs(1,-1);
    up(i,1,n) if (!match[i])
    {
      cout<<"First"; return;
    };
    cout<<"Second";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);// don't use when interactive
    #define TASK "tmp"
   // freopen(TASK".inp","r",stdin);
   // freopen(TASK".out","w",stdout);

    input();
    solve();

    return 0;
}
