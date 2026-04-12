#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

void we_r_done(){cout<<"NO"; exit(0);}

void debug(string mssg){cout<<mssg; exit(0);}

using minHeap = priority_queue< int, vector< int >, greater< int > >;

string K;
int D;
int dp[10001][101][2][2];

int add(int x , int y){
    return (x%mod + y%mod)%mod;
}

int fun(int pos, int md , int isSmall , int isStart){

    if(pos == K.size()) return (!md && !isStart);

    int &ret = dp[pos][md][isSmall][isStart];

    if(ret != -1) return ret;

    ret = 0;

    if(isStart){
        ret = add(ret , fun(pos+1,0,1,1));

        int h = (isSmall?9: K[pos]-'0');

        for(int i=1; i<=h ; i++){
            int d = K[pos]-'0';
            ret = add(ret , fun(pos+1 , (md + i)%D , isSmall || (i<d) , 0) ) ;
        }
    }
    else{
        int h = (isSmall?9: K[pos]-'0');

        for(int i=0; i<=h ; i++){
            int d = K[pos]-'0';

            ret = add(ret , fun(pos+1 , (md + i)%D , isSmall || (i<d) , 0) ) ;
            //cout<<md<<" "<<ret<<endl;
        }
    }
    return ret;
}


int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;
    cin>>K>>D;

    Fill(dp,-1);
    cout<<fun(0,0,0,1);
    return 0;

}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
