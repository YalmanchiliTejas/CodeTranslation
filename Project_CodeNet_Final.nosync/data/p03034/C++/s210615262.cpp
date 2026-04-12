#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
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
int calcA(int N,int k,int C){
  return N-1-k*C;
}
int calcB(int N,int k,int C){
  return N-1-(k+1)*C;
}

int main(void){
  int N;cin >> N;
  ll s[N];
  int i;
  REP(i,N)cin >> s[i];
  //A:(N+1)/2, 
  //C:1,2,...,(N+1)/2-1
  ll maximum = 0;
  for(int C=1;C<(N+1)/2;C++){
    set<int> st;
    ll calc = 0;
    for(int k=0;k*C<N-1;k++){
      if(calcB(N,k,C)<=0 || st.count(k*C) || k*C == N-1-k*C) break;
      calc += s[k*C] + s[N-1-k*C];
      maximum = max(maximum,calc);
      st.insert(N-1-k*C);
    }
  }
  cout << maximum << endl;
  return 0;
}
