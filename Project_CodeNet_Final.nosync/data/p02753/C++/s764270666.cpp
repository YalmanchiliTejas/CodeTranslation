// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task ""
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)

using namespace std;
string s;
bool ok1,ok2;
int main()
{
   ios_base::sync_with_stdio(NULL);
   cin.tie(NULL);
   cout.tie(NULL);
    cin >> s;
    for(int i=0; i<=2; ++i) if(s[i] == 'A') ok1 = 1;
    else ok2 = 1;  
    if(ok1 && ok2) cout << "Yes";
    else cout << "No";
}
