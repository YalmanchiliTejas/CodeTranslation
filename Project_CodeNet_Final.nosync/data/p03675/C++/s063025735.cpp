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
const int INF=1e9*2;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    REP(i,n)
        cin>>a[i];
    if(n%2==0)
    {
        int j=0;
        for(int i=n-1;i>=0;i-=2)
            b[j++]=a[i];
        for(int i=0;i<n;i+=2)
            b[j++]=a[i];
    }
    else
    {
        int j=0;
        for(int i=n-1;i>=0;i-=2)
            b[j++]=a[i];
        for(int i=1;i<n;i+=2)
            b[j++]=a[i];
    }
    REP(i,n)
        cout<<b[i]<<" \n"[i==n-1];
}
