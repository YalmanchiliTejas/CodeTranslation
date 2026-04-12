#include <bits/stdc++.h>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF 1000000007
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;


void Main(){

  int N;
  string s;
  cin>>N>>s;
  vector<string> s1={"SS","WW","SW","WS"};

  rep(x,4){
    reps(i,1,N-1){
      s1[x]+=( !(s1[x][i]==s1[x][i-1]) xor (s[i]=='o') ? 'S' : 'W' );
    }

    if( ( (s1[x][0]==s1[x][N-2]) xor (s[N-1]=='o') xor s1[x][N-1]=='S') and ( (s1[x][N-1]==s1[x][1]) xor (s[0]=='o') xor s1[x][0]=='S' ) ){
      cout << s1[x] <<"\n";
      return;
    }

  }

  cout << -1 <<"\n";
}
//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
