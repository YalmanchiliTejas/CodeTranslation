#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
#include"assert.h"
using namespace std;
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int main()
{
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(a>=k)
    {
        puts("1");
        return 0;
    }
    if(b>=a)
    {
        puts("-1\n");
        return 0;
    }
    cout<<1+2*((k-a+a-b-1)/(a-b))<<'\n';
    return 0;
}