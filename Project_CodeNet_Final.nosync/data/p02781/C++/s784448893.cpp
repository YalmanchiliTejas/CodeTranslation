  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define int long long
  #define all(v) v.begin(),v.end()
  #define f first
  #define s second
  #define PB push_back
  #define MP make_pair
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  #define MOD 998244353
  #define N 200005
  #define INF 1000000000000
  #define eps 1e-6

  vector<int> v;
  int k;
  int dp[1000][1000][2];
 int call(int pos,int cnt,int f)
 {
  if(pos == v.size())
  {
    if(cnt == k) return 1;
    return 0;
  }

  if(dp[pos][cnt][f] != -1)return dp[pos][cnt][f];

  int res = 0;

  int limit;
  if(f == 1)
  {
    limit = 9;
  }
  else
  {
    limit = v[pos];
  }

  int ans = 0;

  for(int i = 0 ; i <= limit; i++)
  {
    int ncnt = cnt;
    if(i != 0)ncnt++;
    int nf = f;
    if(i < v[pos])nf = 1;
    ans += call(pos+1,ncnt,nf);
  }
  return dp[pos][cnt][f] = ans;
 }
 int solve(string s)
 {
  v.clear();

  for(int i = 0; i< s.length(); i++)
  {
    v.PB(s[i] - '0');
  }
 

  memset(dp,-1,sizeof(dp));
  int res = call(0,0,0);
  return res;
 }


int32_t main()
{


    string s;
    cin >> s >> k;

    cout << solve(s) << endl; 


    return 0;
}