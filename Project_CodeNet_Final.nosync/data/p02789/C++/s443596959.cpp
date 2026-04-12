#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mp make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const unsigned ll l=1000000007;
const int MAX_=2000;
int T;
 
void print(string res, int i)
{
  printf("Case #%d: %s\n",T-i,res.c_str());
  // cout << res;
}
void print(ll res, int i)
{
  printf("Case #%d: %lld\n",T-i,res);
  // cout << res;
}

void solve(int t)
{
  ll a,b;
  cin >> a >> b;
  if(a == b)
  {
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}
 
int main()
{
  IOS
  int t,testCases;
  testCases=1;
  #ifdef DEBUG
    freopen("input.txt","r",stdin);
    cin >> testCases;
    cout << "Running " << testCases << " testcases" << endl;
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
  #endif
 
 
  while(testCases--)
  {
    t=1;
    // cin >> t; //comment this in case of singular test case
    T = t;
    while(t--)
    {
      solve(t);
    }
  }
  return 0;
 
}