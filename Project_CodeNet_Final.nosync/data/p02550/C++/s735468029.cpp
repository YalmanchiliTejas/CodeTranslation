#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define For(i, a) for (int i=0; i<a; i++)
#define FORR(i,a,b) for (int i = a; i >= b; i--)
#define Forr(i,a) for (int i = a; i >= 0; i--)

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args)
{cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }

void solve(){
  int n,a,m; cin >> n >> a >> m;
  vector<int> pref(m+1,0);
  vector<int> visited(m+1,0),noCycle,Cycle;
  int i=0;
  while(1){
    if(visited[a]){
      for(int j=0;j<(int)noCycle.size();j++){
        if(noCycle[j]==a){
          int k=j;
          while(k<(int)noCycle.size()){
            Cycle.push_back(noCycle[k]);
            k++;
          }
          break;
        }
      }
      if(a==0){
        cout << pref[i-1] << "\n";
        return;
      }
      break;
    }
    else{
      visited[a]=1;
      noCycle.push_back(a);
      if(i>0)pref[i]=pref[i-1]+a;
      else pref[i]=a;
    }
    a = (a%m*a%m)%m;
    i++;
    if(i>=n){
      cout << pref[i-1] << "\n";
      return;
    }
  }
  int len1=noCycle.size()-Cycle.size();
  int tt = (n-len1)/((int)Cycle.size());
  vector<int> pref1(m+10,0);
  
  if(Cycle.size()>0)pref1[0]=Cycle[0];
  for(int j=1;j<(int)Cycle.size();j++){
    pref1[j]=pref1[j-1]+Cycle[j];
  }  
  int len2=Cycle.size();
  int sum=(len1-1>=0?pref[len1-1]:0)+tt*(pref1[len2-1]);
  if((n-len1)%tt-1>=0){
    sum += pref1[(n-len1)%tt-1];
  }
  cout << sum << "\n";
}


int32_t main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  for(int tt=1;tt<=t;tt++){
    solve();
  }
}
