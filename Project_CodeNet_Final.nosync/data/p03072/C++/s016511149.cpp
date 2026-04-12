#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)



int main()
{
  int N;
  cin >> N;
  vector<int> h(N);
  rep (i,N) cin >> h.at(i);
  
  int count = 1;
  rep(i,N){
   if (i == 0) continue;
    bool see = true; 
    rep(j,i){
       if (h.at(j) > h.at(i)) see = false;
     }
    if (see) count++;
  }
  
  cout << count <<endl;
  
  
    return 0;
}
