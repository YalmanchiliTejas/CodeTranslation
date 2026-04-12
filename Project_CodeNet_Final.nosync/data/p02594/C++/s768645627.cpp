   //____________________________________________________________________\\
  //________________________________NAMAN_________________________________\\
 //________________________________TALAYCHA________________________________\\
//__________________________________________________________________________\\

#include <bits/stdc++.h>
#define ll long long
#define what_is(x)  cerr << #x << " is " << x << endl;
#define pmin priority_queue <int, vector<int>, greater<int> >
#define pmax priority_queue <int>
typedef long double ld;
#define sz(a) int((a).size())
 #define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define mii map<ll , ll >
#define mis map<ll int, string>
#define msi map<string, ll int>
#define pii pair<ll int, ll int>
#define vi vector<ll>
#define st set<ll>
#define vii vector<pair<ll int, ll int>>
#define vs vector<string>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define mp make_pair
#define INF (1ll << 60)
#define DEBUG    cerr<<"/n>>>I'm Here<<</n"<<endl;
#define rep(i, a, b )   for (ll i = a; i < b; i++)
#define tep(i, a, b )   for (ll i = a; i < b; i = i + 2)
#define rrep(i, a, b)  for (ll i = a; i >= b; i--)
#define bs binary_search
#define mp make_pair
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 200200
#define mod 998244353


#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
cin.tie(0);                                                                  \
cout.tie(0);

using namespace std;
 /*

 ll fun (ll a,ll b , int m )
 {
   if(b==0)
   return 1;
   else if(b%2==0)
   {
     return fun((a*a)%m,b/2,m);
   }
   else
   return a*fun((a*a)%m,(b-1)/2,m)%m;
 
 }
 */

 //___________________________________________________________________________
//-------------------------START----------------------------------------------

//int s;


void solve()
{
  ll n,m=0,mi=INT_MIN,z=0;
int x;
 cin>>x;
  if(x>=30)
  {
  cout<<"Yes";
  return ;
  }
  cout<<"No";
  return ;
}


   //___________________________________________________________________________
//---------------------------END----------------------------------------------




int main() {

  // int t=1000000;
   //sieve(N);
    #ifndef ONLINE_JUDGE 
  freopen("input.txt" , "r", stdin);
  freopen("out12.txt" , "w", stdout);
    #endif  

  ios int TESTS = 1;
  //cin>>TESTS;
  while (TESTS--) {
    solve();
  }
  
  return 0;
}
