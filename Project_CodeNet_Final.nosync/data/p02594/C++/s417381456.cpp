///Nahid Hasan Raju
#include <bits/stdc++.h>
#define ll long long
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define Fin freopen("input.txt","r",stdin)
using namespace std;

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


/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

ll m, n;
ll a[MX], b[MX];
string s,s1;
map<ll,int>mp;

void precalc(ll p)
{

}

///cerr<<   how to use it?
int main()
{
    #ifndef ONLINE_JUDGE
    Fin;
    #endif
    int test=1, tc=0, i, j;
    ll k, ans;
    //scanf("%d", &test);
    //precalc(1);
    while(test--)
    {
        j=0;
        cin>>n;
        if(n>=30)puts("Yes");
        else puts("No");
        //printf("%lld\n", ans);
    }
    return 0;
}

