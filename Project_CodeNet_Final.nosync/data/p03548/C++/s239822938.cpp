/********************************
Auther: jianwei
blog  : http://blog.csdn.net/jianwei2016
********************************/

#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
#define FILEIN freopen("in.txt","r",stdin)
#define FILEOUT freopen("out.txt","w",stdout)
#define CLR(x) memset(x,0,sizeof(x))
#define MEM(a,x) memset(a,x,sizeof(a))
#define PB(x) push_back(x)
#define PF(x) push_front(x)
#define For(x,a,b) for(int x=a;x<b;x++)
#define rFor(x,a,b) for(int x=a;x>b;x--)
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define rFOR(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&(-x))

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const double eps = 1e-6;
const ll mod = 1e9+7;
const int maxn = 100100;
const int maxe = 100100;

void Solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    a-=c;
    while(1){
        a-=(b+c);
        if(a<0){
            break;
        }
        else cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
    //FILEIN
    //FILEOUT
    std::ios::sync_with_stdio(false);
    ll Case=1,cases;
    //cin>>Case;cases=Case;
    while(Case--){
        //printf("Case #%d:",cases-Case);
        Solve();
    }
    return 0;
}
