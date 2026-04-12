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
const int N= (int) 2e5+10;
int b[N],a[N],n;
void input()
{
    cin>>n;
    up(i,1,n) cin>>a[i];

}

void solve()
{
	if (n==1)
	{
		cout<<a[1]; return;
	}
    int top= n-1, bot= 0;
    up(i,1,n)
    {
    	if (i%2==1)
		{
			top= (top+1) %n;
			b[top]= a[i];
		}
    	else
		{
			bot= (bot-1+n)% n;
			b[bot]= a[i];
		}

    }
    if (n%2==1)
	{
		down(i,top,0) cout<<b[i]<<" ";
		down(i,n-1,bot) cout<<b[i]<<" ";
	}
	else
	{
        up(i,bot,n-1) cout<<b[i]<<" ";
        up(i,0,top) cout<<b[i]<< " ";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);// scanf phai bo
    #define TASK "tmp"
   // freopen(TASK".inp","r",stdin);
   // freopen(TASK".out","w",stdout);

    input();
    solve();

    return 0;
}
