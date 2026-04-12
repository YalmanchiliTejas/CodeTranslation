#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<(int)(y);++i)
#define FORE(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=2e9;
const int MOD=1e9+7;
const int MAXN=1e6+7;

int ans=0;
int n,m,k,q;
string s;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2])cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
