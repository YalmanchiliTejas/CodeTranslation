#include <bits/stdc++.h>
using namespace std;
#define cool ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fe first
#define se second
#define endl "\n"
#define pii pair<int, int>

#define PI 3.14159265358979323846
const int N = 3005 + 10;
ll dp[N][N];

void solve() {
 int n;
 cin>>n;
 vector<int> a(n);
 for(int i=0;i<n;i++)
    cin>>a[i];
 
 
 
 for(int  i=n-1;i>=0;i--) {
	  for(int j=i;j<n;j++) {
		    if(i==j)
		      dp[i][j]=a[i];
		   else
		      dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);   
		  }
	 
	 }
	 
	 cout<<dp[0][n-1];
	 
	 
}
int main() {
  cool;
  int t = 1;
  while (t--)
    solve();

  return 0;
}
