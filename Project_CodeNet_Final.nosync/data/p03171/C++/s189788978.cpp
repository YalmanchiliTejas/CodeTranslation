#include <bits/stdc++.h>  

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) 
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) 
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) 
#define forrc(i,l,r) for (int i= (int)(r); i>= (int)(l); --i)

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin, (x).rend() 


#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)


#define present(c,x) ((c).find(x) != (c).end())


#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sz(a) int((a).size())

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef long long ll;
typedef unsigned long long int ull;

int MOD=1000000007;

int main(){
  fastio; 
  
  int n;
  cin >> n;
  ll a[n];
  ll sum=0;
  for0(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  ll dp[n][n];
  int l,r;
  for0(i,n){
    l=0,r=i;
    while(r<n){
      if(l==r){
        dp[l][r]=a[l];
        l++;
        r++;
        continue;
      }
      if(l+1==r){
        dp[l][r]=max(a[l],a[r]);
        l++;
        r++;
        continue;
      }
      dp[l][r]=max(a[l]+min(dp[l+1][r-1],dp[l+2][r]),a[r]+min(dp[l][r-2],dp[l+1][r-1]));
      l++;
      r++;
    }
  }
  cout << 2*dp[0][n-1]-sum;
}