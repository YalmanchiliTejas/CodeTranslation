#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void  solve(){
  int h,w;
  cin>>h>>w;
  int dp[h][w];
  char x;
  rep(i,0,h){
    rep(j,0,w){
      cin>>x;
      if(x=='.') dp[i][j]=1;
      else dp[i][j]=0;
    }
  }
  set<int> r,c;
  rep(i,0,h){
    int ans=1;
    rep(j,0,w){
      ans=ans&dp[i][j];
    }
    if(ans) r.insert(i);
  }
  rep(j,0,w){
    int ans=1;
    rep(i,0,h){
      ans=ans&dp[i][j];
    }
    if(ans) c.insert(j);
  }
  rep(i,0,h){
    if(r.find(i)!=r.end()) continue;
    int flag=0;
    rep(j,0,w){
      if(c.find(j)!=c.end()) continue;
      flag=1;
      if(dp[i][j]) cout<<'.';
      else cout<<'#';
    }

    if(flag) cout<<endl;
  }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
