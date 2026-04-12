#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef  vector<int> vi;
typedef  pair<int,int> pii;
typedef  pair<int,string> pis;
double   pi=3.1415926535898;
#define speed      ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define lop(i,n)   for(int i=0;i<int(n);i++)
#define rep(i,a,b) for(int i=a;i<=int(b);i++)
#define rng(i,a,b) for(int i=a;i>=int(b);i--)
#define ms(x,a)    memset(x,a,sizeof(x))
#define all(x)     (x).begin(),(x).end()
#define sz(x)      int(x.size())
#define pb         push_back
#define r0         return 0;
#define CC         continue;
#define bb(x)      cerr<< x <<endl;
#define F          first
#define S          second       //  __builtin_popcount;
//freopen("output.txt","w",stdout),freopen("input.txt","r",stdin);
const ll M  = 1e9+7 ;
const int N = 100100;
const int inf = INT_MAX;
const double eps = 1e-7;
const ll iinf = -1e18 ;
//////////////////////    Hi    ^_^  hack me if you can :P

int main()
{
    speed;
    int a,b;
    a = 0;
    a*=10;
    cin >> b;
    a+=b;
    a*=10;
    cin >> b;
    a+=b;
    a*=10;
    cin >> b;
    a+=b;
    if (a%4==0){
        cout <<"YES";
    }else {
        cout <<"NO";
    }

}
