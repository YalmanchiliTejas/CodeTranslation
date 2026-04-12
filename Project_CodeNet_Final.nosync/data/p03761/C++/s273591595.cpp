#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define for01(k,n)  for (ll i=k; i<n; i++)
#define for02(k,n)  for (ll j=k; j<n; j++)
#define for03(k,n)  for (ll k=k; k<n; k++)
#define for11(k,n)  for (ll i=k; i<=n; i++)
#define for12(k,n)  for (ll j=k; j<=n; j++)
#define for13(k,n)  for (ll k=k; k<=n; k++)

#define pb push_back
#define mp make_pair
#define pf push_front
#define popf pop_front
#define popb pop_back
#define vll vector<ll>
#define F first
#define S second
#define pp pair <ll, ll>
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define si size()
#define bk back()
#define deci(n)  fixed<<setprecision(n)
#define mll map<ll,ll>
#define mint map<int,int>
#define mll_it map<ll,ll>::iterator
#define mint_it map<int,int>::iterator

#define p0(a) cout << a << " "
#define p1(a) cout << a << "\n"

#define mem(a,n) memset(a, n, sizeof(a)); // n = 0 OR -1 only

#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
#define MOD2 998244353


int main()
{
    //BOOST;
    ll n;
    cin >> n;
    string *a = new string[n];

    for01(0, n)
        cin >> a[i];

    string ans = "";
  	string t = a[0];
  	ll l = t.length();
  
  	for01(1, n)
    {
      if(l > a[i].length())
      {
        l = a[i].length();
        t = a[i];
      }
    }
  	//p1(t);
  	
    for01(0, l)
    {
        ll f = 0;
        for02(0, n)
        {
			
              	//p1(j);
               	auto found = a[j].find(t[i]);
            	if(found != std::string::npos)
            	{
              	  f++;
              	  //p1(i << " Found = " << found << " " << a[j][found]);
              	  a[j][found] = '0';
          	 	}
            
        }
        if(f == n)
            ans += t[i];
      //p1(f);
    }

    sort(ans.begin(), ans.end());
    p1(ans);

    return 0;
}