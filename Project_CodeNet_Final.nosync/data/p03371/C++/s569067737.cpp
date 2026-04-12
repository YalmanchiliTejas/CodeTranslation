#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int s,t,u,z=max(x,y);
    s=a*x+b*y;
    t=((x>y)? c*2*y+a*(x-y):c*2*x+b*(y-x));
    u=c*2*z;

    cout<<min(min(s,t),u)<<endl;

	return 0; 
}