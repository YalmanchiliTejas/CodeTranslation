#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using VPI = vector<PII>;
using VPL = vector<PLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  const LL up_to = 300010;
  LL n,x,m;
  cin >> n >> x >> m;
  VLL checked(m,0),a(min(n+1,up_to),-1);
  a[1] = x;
  checked[x]++;
  bool start = false;
  LL span = 0, sum_span=0, sum=x, mark;
  
  REP(i,2,n+1){
    a[i] = (a[i-1]*a[i-1]) % m;
    checked[a[i]]++;
    sum += a[i];
    if(checked[a[i]] == 2){
      start = true;
    }
    if(checked[a[i]] == 3){
      mark = i-1;
      sum -= a[i];
      break;
    }
    if(start){
      span++;
      sum_span += a[i];
    }
  }
  
  if(a[a.size()-1] >= 0){
    cout << sum << endl;
    return 0;
  }
  
  sum += ((n-mark)/span)*sum_span;
  LL rest = (n-mark) % span;
  LL cnt = mark - (2*span) + 1;
  REP(i,0,rest){
    sum += a[cnt+i];
  }
  cout << sum << endl;

  
  return 0;
}
