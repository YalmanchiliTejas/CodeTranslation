///Nahid Hasan Raju
#include <bits/stdc++.h>
#define ll long long
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define Fin freopen("input.txt","r",stdin)
using namespace std;

#define P(XX) cout<<XX<<endl
#define P1(XX) cerr<<"db1: "<<XX<<endl
#define P2(XX,YY) cerr<<"db2: "<<XX<<" "<<YY<<endl
#define P3(XX,YY,ZZ) cerr<<"db3: "<<XX<<" "<<YY<<" "<<ZZ<<endl
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Fout freopen("output.txt","w",stdout)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define EPS 0.00000001
#define INF INT_MAX
#define PI 2*acos(0.0)
#define set(XX,POS) XX|=(1<<POS)
#define reset(XX,POS) XX&=(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree< pair<int,int> , null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> odrst;

#define MOD 1000000007ll
#define MX 2000006  ///200005

ll m, n;
ll a[MX], b[MX];
string s,s1;
map<ll,int>mp;

void func(ll p)
{

}
int main()
{
    int test=1, tc=0, i, j;
    #ifndef ONLINE_JUDGE
    //Fin;
    test=3;
    #endif
    ll k, ans, t, kk;
    //scanf("%d", &test);
    while(test--)
    {
        j=k=ans=0;
        cin>>n;
            for(i=1;i<=n;i++)
            {
                cin>>j;
                b[i]=j;
                a[i]=j+a[i-1];
            }
            for(i=1;i<=n;i++)
            {
                k=a[n]-a[i];
                k%=MOD;
                ans+=(k*b[i])%MOD;
            }
            ans%=MOD;

        P(ans);
        return 0;

        if(t)puts("YES");
        else puts("NO");

        printf("%lld\n", ans);
        for(i=0;i<ans;i++)
        {
            printf("%lld", b[i]);
        }
    }
    return 0;
}

