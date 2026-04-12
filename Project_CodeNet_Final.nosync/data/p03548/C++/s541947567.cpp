#include <bits/stdc++.h>
using namespace std;
     
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7
     
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    int a=x-z,b=y+z;
    cout<<a/b<<endl;
}