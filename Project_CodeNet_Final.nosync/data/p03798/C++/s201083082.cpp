#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

int N;
string s;

bool check(vector<char>& v){
  int isseap;
  repp(i,1,N-1){
    isseap = 1;
    if(v[i] !='S') isseap^=1;
    if(s[i] != 'o') isseap^=1;
    if(v[i-1] != 'S') isseap ^=1;
    if(isseap)v[i+1] = 'S';
    else v[i+1] = 'W';
  }
  //0を見る
  isseap = 1;
  if(v[0] !='S') isseap ^=1;
  if(s[0] != 'o') isseap^=1;
  if(v[N-1] != 'S') isseap ^=1;
  if(isseap && v[1] == 'W') return false;
  if(!isseap &&  v[1] == 'S') return false;

  //N-1を見る
  isseap = 1;
  if(v[N-1] !='S') isseap ^=1;
  if(s[N-1] != 'o') isseap^=1;
  if(v[N-2] != 'S') isseap ^=1;
  if(isseap && v[0] == 'W') return false;
  if(!isseap &&  v[0] == 'S') return false;

  return true;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  cin >> N;
  cin >> s;
  vector<char> v(N,'S');
  if(check(v)){
    rep(i,N) cout << v[i];
    cout << endl;
    return 0;
  }
  v[1] = 'W';
  if(check(v)){
    rep(i,N) cout << v[i];
    cout << endl;
    return 0;
  }
  v[0] = 'W';
  if(check(v)){
    rep(i,N) cout << v[i];
    cout << endl;
    return 0;
  }
  v[1] = 'S';
  if(check(v)){
    rep(i,N) cout << v[i];
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
