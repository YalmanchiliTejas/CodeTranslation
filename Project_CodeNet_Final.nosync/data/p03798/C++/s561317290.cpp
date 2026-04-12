// ABC 055 D
#include<bits/stdc++.h>
 
using namespace std;
//container util
//------------------------------------------
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).begin(),(c).end(),greater<int>())

#define PB(a) push_back(a)

#define ALL(x) (x).begin(),(x).end()
#define MAX_EL(c) *max_element((c).begin(),(c).end())
#define MIN_EL(c) *min_element((c).begin(),(c).end())
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef string str;
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

str s; 

char make(str a,int i){
  if(a[i]=='S'){
    if(s[i]=='o'){
      if(a[i-1]=='S')  return 'S';
      else return'W';
    }
    else if(s[i]=='x'){
      if(a[i-1]=='S') return 'W';
      else return 'S';
    }
  }
  else if(a[i]=='W'){
    if(s[i]=='o'){
      if(a[i-1]=='S')  return 'W';
      else return 'S';
    }
    else if(s[i]=='x'){
      if(a[i-1]=='S') return 'S';
      else return 'W';
    }
  }
}
bool check(str a,int i,int n){
  if(a[(i+n)%n]=='S'){
    if(s[(i+n)%n]=='o'){
      if (a[(i+n-1)%n]==a[(i+n+1)%n]) return true;
      else return false;
    }
    else if(s[(i+n)%n]=='x'){
      if (a[(i+n-1)%n]!=a[(i+n+1)%n]) return true;
      else return false;
    }
  }
  else if(a[(i+n)%n]=='W'){
    if(s[(i+n)%n]=='o'){
      if (a[(i+n-1)%n]!=a[(i+n+1)%n]) return true;
      else return false;
    }
    else if(s[(i+n)%n]=='x'){
      if (a[(i+n-1)%n]==a[(i+n+1)%n]) return true;
      else return false;
    }
  }
}

int main(){
// magic spell------------------------------
  cin.tie(0);
  ios::sync_with_stdio(false);
//------------------------------------------

  int n,k;
  str ans;
  cin >> n;
  cin >> s;
  str s1 = "SS";
  str s2 = "SW";
  str s3 = "WS";
  str s4 = "WW";
  vector <string> ss{s1,s2,s3,s4};
  EACH(i,ss){
    FOR(j,1,n-1){
      *i+=make(*i,j);
    }
    if(check(*i,n-1,n)&&check(*i,0,n)) {
      ans = *i;
      break;
    }
  }
  if(ans=="")ans="-1";
  cout << ans << endl;
  return 0;
}
