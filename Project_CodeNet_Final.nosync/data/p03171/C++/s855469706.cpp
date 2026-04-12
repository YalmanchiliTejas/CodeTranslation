#include <bits/stdc++.h>
#define OP_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fo(i,a,b) for(int i = a; i < b; i++)
#define foi(i,a,b) for(int i = a; i>=b; i--)
#define fi first
#define si second
#define pb push_back
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const ll INF = 1e18L + 5;
const int MAXN = 3005;
const ll modn = 1e9+7;

ll dp[MAXN][MAXN];

ll solve(vll &a, int low, int high){
  if(low == high){
    return dp[low][high] = a[low];
  }
  if(dp[low][high] != -1){
    return dp[low][high];
  }
  dp[low][high] = max(a[low] - solve(a, low+1, high), a[high] - solve(a, low, high-1));
  return dp[low][high];
}

ll solve(vll &a){
  int n = a.size();
  fo(i, 0, n){
    fo(j, 0, n){
      dp[i][j] = -1;
    }
  }
  solve(a, 0, n-1);
  return dp[0][n-1];
}

void printval(int n){
  fo(i,0,n){
    fo(j,0,n){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
}

ll solve1(vll &a){
  int n = a.size();
  ll dp1[n][n];
  fo(i,0,n){
    fo(j,0,n){
      dp1[i][j] = -1;
    }
  }
  foi(i, n-1, 0){
    fo(j, i, n){
      if(i == j){
	dp1[i][j] = a[i];
      }else{
	dp1[i][j] = max(a[i] - dp1[i+1][j], a[j] - dp1[i][j-1]);
      }
			
    }
  }
  return dp1[0][n-1];
}

int main(){
  OP_IO;
  int n;
  cin>>n;
  vll a(n);
  fo(i,0,n){
    cin>>a[i];
  }
  //cout<<solve(a)<<endl;
  cout<<solve1(a)<<endl;
  //printval(n);
  return 0;
}
