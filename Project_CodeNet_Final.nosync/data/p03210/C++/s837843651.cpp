#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main()
{int x;
 cin >> x;
 
 bool  k = false;
 if (x == 3 || x == 5 || x == 7) k = true;
 
 cout << (k ? "YES" : "NO" ) << endl;
 
    return 0;
}
