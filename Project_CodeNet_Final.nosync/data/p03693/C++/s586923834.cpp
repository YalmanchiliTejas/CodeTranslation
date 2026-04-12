// Template by [thunder_blade]
// IIIT ALLAHABAD
// includes :)

#include <bits/stdc++.h>
#include <ext/rope> 
using namespace __gnu_cxx;
using namespace std;
#define TEST  int test_case; cin>>test_case; while(test_case--)
#define all(v) (v).begin(),(v).end()
#define fi  first
#define se  second
#define pb push_back
#define mp make_pair
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define pf(x) printf("%f\n",x)
#define ps(x) printf("%s\n",x)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sf(x) scanf("%f",&x)
#define ss(x) scanf("%s",x)
#define pis(x) printf("%d ",x)
#define pls(x) printf("%lld ",x)
#define pfs(x) printf("%f ",x)
#define pss(x) printf("%s ",x)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007

const int INF = (int)1e8;
const int N = 500005;

int main()
{
    int a,b,c;
    si(a), si(b), si(c);
    int num = a*100 + b*10 +c;

    if(num%4 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
}
