#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()

const double eps=1e-5;
const LL INF=(LL)1e9*(LL)1e9;


int main()
{
    LL n;
    cin>>n;
    vector<LL> a(n);
    REP(i,n)
        cin>>a[i];
    
    bool flag=1;
    LL cnt=0;
    while(flag)
    {
        flag=0;
        REP(i,n)
        {
            if(a[i]<=n-1) continue;
            flag=1;
            LL p=a[i]/n;
            cnt+=p;
            a[i]%=n;
            REP(j,n)
            {
                if(i==j) continue;
                a[j]+=p;
            }
        }

        /*REP(i,n)
            cout<<a[i]<<" \n"[i==n-1];*/
    }
    cout<<cnt<<endl;
}
