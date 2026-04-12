#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a ; i <= b ; i++)
#define REPI(i,a,b) for (int i = a ; i >= b ; i--)
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll OO = 1e18+7;
const int MOD = 1e9+7;
const int N = 1e4+7;
const int D = 1e2+7;
string k;
int d;
ll mem[N][D][2];

ll dp(int i,int sum,bool b)
{
    ll &ret = mem[i][sum][b];
    if (ret != -1) return ret;
    if (i == 1e4) return (sum == 0);
    // b = 1 : no need for checking
    // b = 0 : we have to check
    ret = 0;
    if (b)
    {
        REP(j,0,9)
        {
            ret = (ret + dp(i+1,(sum+j)%d,1))%MOD;
        }
    }
    else
    {
        REP(j,0,k[i]-'0'-1)
        {
            ret = (ret + dp(i+1,(sum+j)%d,1))%MOD;
        }
        ret = (ret+dp(i+1,(sum+k[i]-'0')%d,0))%MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);
    memset(mem,-1,sizeof mem);
    cin >> k >> d;
    reverse(k.begin(),k.end());
    while(k.size() < 1e4) k.PB('0');
    reverse(k.begin(),k.end());

    cout << (dp(0,0,0)-1+MOD)%MOD << endl;

    return 0;
}
