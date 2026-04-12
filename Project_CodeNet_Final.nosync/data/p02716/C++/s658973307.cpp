#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define endl "\n"
#define loop(i,s,e) for(int i=s;i<e;i++)
#define int long long
#define mp make_pair
#define pii pair<int,int>
#define mset(a,f)  memset(a , f , sizeof(a))
#define pb push_back
const int N = 2e6 + 6;
const int inf = 1e18;
const int M = 1e9 + 7;
int A[N];
int dp[N][6][2];
int n , k = 0 , l = 0;

int alpha(int id , int cnt , int ok)
{
      if(id == n && n%2 && ok)return 0;
      if(id > n)return 0;
      int &abs = dp[id][cnt][ok];
      if(abs != -1)return abs;
      int ans = 0,a1 = -inf,a2 = -inf;
      if(cnt < k)
      {
            a1 = alpha(id+1,cnt+1,0);
            a2 = A[id] + alpha(id+2,cnt,ok); 
      }
      if(cnt == k)
      {
            a1 = A[id] + alpha(id+2,cnt,ok);
      }
      ans  = max(a1,a2);
      return abs = ans;
}

void solve()
{
      cin >> n;

      mset(dp,-1);

      loop(i,1,n+1)cin >> A[i];

      k = n%2;
      k++;
      int a1 = alpha(1,0,n%2);
      k--;
      int a2 = alpha(2,0,n%2);

      cout << max(a1,a2);
}
 
int32_t main()
{
 
ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
    

       
       int t = 1;
       // cin >> t;
       while(t--)solve();
        
}
