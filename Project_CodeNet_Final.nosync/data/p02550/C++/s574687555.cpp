#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MODADD(ADD_X,ADD_Y)  (ADD_X+ADD_Y)%MOD;
#define MODSUB(SUB_X,SUB_Y)  (SUB_X-SUB_Y)+MOD)%MOD;
#define MODMUL(MUL_X,MUL_Y)  (MUL_X*MUL_Y)%MOD;
#define LCM(LCM_X,LCM_Y) (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,x,y,sum=0;
    cin>>n>>x>>y;
    map<int,int>mp;
    vector<int>v;
    int st;
    while(n-- && x)
    {
        mp[x]++;
        if(mp[x]==2)
            v.push_back(x);
        if(mp[x]==3)
        {
            n++;
            break;
        }
        sum+=x;
        x=(x*x);
        x%=y;


        //cout<<x<<" "<<mp[x]<<endl;
    }
    int sz=v.size();
    if(sz && n>0)
    {
        ll cur=0;
        for(int i=0; i<sz; i++)
        {
            cur+=v[i];
        }
        ll mul=n/sz;
        ll rem=n%sz;
        for(int i=0; i<rem; i++)
        {
            sum+=v[i];
        }
        sum+=(mul*cur);
    }
    cout<<sum<<endl;

    return 0;
}

