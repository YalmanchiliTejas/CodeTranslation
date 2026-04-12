#include <bits/stdc++.h>
using namespace std;

// in-short-use macros

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007

//container-use 

typedef vector< ll > vl;
typedef vector< vl > vvl;
typedef pair< ll,ll > pll;
typedef vector<pair<ll,ll > > vpl;
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define rep(i,a,b) for (int i = a; i <= b; i++)

//main function here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    if(m==n)
        cout<<"Yes\n";
    else
        cout<<"No\n";
  return 0;
 }
