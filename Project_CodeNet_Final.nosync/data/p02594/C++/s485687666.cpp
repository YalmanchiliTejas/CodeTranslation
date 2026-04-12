#include<bits/stdc++.h>
#include<vector>
#include<string>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#include<set>
#define ws " "
#define nl "\n"
#define tc ll test; cin>>test; while(test--)
#define f(i, a, b) for(ll i = a; i<b; i++)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#include<fstream>

using namespace std;

#define pll pair<ll, ll>
bool compare(pll a, pll b)
{
	//for descending order replace with a.roll >b.roll
   if((a.ff < b.ff)||((a.ff==b.ff)&&a.ss<b.ss))
        return 1;
	else
		return 0;
}

ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}


void solve()
{
  int x;
  cin>>x;

  if(x>=30)
    cout<<"Yes"<<nl;
  else cout<<"No"<<nl;
}


int main()
{
    fastIO;
   // tc

    //cout<<"Case #"<<i+1<<" :"<<nl;
    solve();


}
