#include <bits/stdc++.h>
using namespace std;
#define print printf("==================\n")
#define ll long long
#define pi acos(-1.0)
#define eps 1e-16
#define max3(a,b,c) max(a,max(b,c))
#define mod 1000000007
const ll INF = 1 << 30;
#define mod 1000000007
typedef pair<double, double  > payar;
typedef struct
{
    ll  x, y;
} point;
priority_queue<payar, vector<payar>,  greater<payar> > pq; ///accending
vector< pair<double,payar  > > vpp;
vector < payar >  vp;
string  num;
ll a, b, d, k;
ll DP[10005][105][2];

ll call(ll pos, ll sum, int flag )
{


    if(pos==num.size())
    {

        ll p = sum%d;
        if(p%d==0)
            return 1;

        else
            return 0;
    }

    if(DP[pos][sum][flag] !=-1 )
    {
        return DP[pos][sum][flag] ;
    }

    ll res = 0 ;

    ll lim;

    if(flag==0)
    {
        lim = num[pos]-48;
    }
    else
    {
        lim = 9;
    }
    for(int dgt = 0 ; dgt <=lim ; dgt++)
    {
        ll nf=flag ;
        ll cn=sum%d;
        if(flag==0 and dgt<lim)
            nf=1;
        cn+=dgt;
        cn=cn%d;


        res= (res%mod+call(pos+1,cn,nf))%mod;

    }
    return DP[pos][sum][flag] = res;

}



ll solve()
{

    memset(DP, -1, sizeof(DP));
    ll res = call(0, 0, 0);
    return res;
}

int main ()
{
    getline(cin, num);
    cin>>d;
    ll res = solve();

    cout << (res-1+mod)%mod << endl;


    return 0;
}
