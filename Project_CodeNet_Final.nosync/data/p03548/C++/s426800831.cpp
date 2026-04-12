/*  
    Talkin' to myself and feelin' old
    Sometimes I'd like to quit, nothin' ever seems to fit
    Hangin' around, nothin' to do but frown
    Rainy days and Mondays always get me down
    _________________________
    _________________________
    912 Hours of Solitude
    Quarantine_Day : 38
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;
typedef pair<ll, ll>		pll;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<int>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 50005

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, z;
    cin>>x>>y>>z;

    ll rem = x - z;
    cout<<rem / (y + z)<<"\n";

    return 0;
}
