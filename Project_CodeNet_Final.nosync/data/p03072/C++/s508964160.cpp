#include <bits/stdc++.h>
#define int long long
using namespace std;

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<PII> VP;


//REPEAT
//------------------------------------------
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i > n;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,m)  RFOR(i,m,0)

//container util
//------------------------------------------
#define pb(a) push_back(a)
#define fst first
#define snd second
#define SORT(V) sort((V).begin(),(V).end())
#define REV(V) reverse((V).begin(),(V).end())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//grobal variable
//------------------------------------------

//def function, class
//------------------------------------------
class MyClass         // 中身が空のクラス宣言
{
};
//main
//------------------------------------------
signed main(){
  int N;
  cin >> N;
  VI H(N);
  REP(i ,N) cin >> H.at(i);

  int ans=0;
  REP(i, N){
    int count=0;
    REP(j, i){
      if(H.at(i)>=H.at(j)) count++;
    }
    if(count==i) ans++;
  }

  cout << ans << endl;
  return 0;

}
