#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#include<iomanip>
#define BUG puts("no bug")
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define ll long long
#define ull unsigned long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define PER(a,b,c) for(int a=b;a>=c;a--)
#define lb(a) (a&(-a))
#define pp (p<<1)
#define ppp (p<<1|1)
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
using namespace std;
const int MAXN=1e6+5;
int n,m,t;
int v[MAXN];
char s[MAXN];
string A="BBB";
string B="AAA";
int main(){
    string s;
    cin>>s;
    if(s!=A&&s!=B)cout<<"Yes";
    else cout<<"No";
}