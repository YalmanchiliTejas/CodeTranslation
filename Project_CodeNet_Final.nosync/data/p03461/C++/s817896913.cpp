#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int main()
{
  int a, b; cin>>a>>b;
  int d[11][11];
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      cin>>d[i][j];
    }
  }
  int p[11][11], q[11][11], r[11][11];
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      bool ok=0;
      for(int k=0; k<=100; k++){
        for(int l=0; l<=100; l++){
          if(d[i][j]<k*i+l*j) continue;
          bool nuee=0;
          for(int s=1; s<=a; s++){
            for(int t=1; t<=b; t++){
              if(d[s][t]>d[i][j]+k*(s-i)+l*(t-j)){
                nuee=1;
                break;
              }
            }
            if(nuee) break;
          }
          if(!nuee){
            p[i][j]=k, q[i][j]=l, r[i][j]=d[i][j]-(k*i+l*j);
            ok=1;
            break;
          }
        }
        if(ok) break;
      }
      if(!ok){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }
  int n=202;
  int s=1, t=n;
  vector<P> g[205];
  set<P> st;
  int m=0;
  for(int i=1; i<=n/2-1; i++){
    g[i].push_back(P(i+1, -1)); m++;
  }
  for(int i=n/2+1; i<=n-1; i++){
    g[i].push_back(P(i+1, -2)); m++;
  }
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      if(st.find(P(1+p[i][j], n-q[i][j]))!=st.end()) continue;
      st.insert(P(1+p[i][j], n-q[i][j]));
      g[1+p[i][j]].push_back(P(n-q[i][j], r[i][j])); m++;
    }
  }/*
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      int dp[205];
      fill(dp+1, dp+n+1, 10000);
      dp[1]=0;
      for(int k=1; k<=n; k++){
        for(auto e:g[k]){
          if(e.second==-1) dp[e.first]=min(dp[e.first], dp[k]+i);
          else if(e.second==-2) dp[e.first]=min(dp[e.first], dp[k]+j);
          else dp[e.first]=min(dp[e.first], dp[k]+e.second);
          
        }
      }
      cout<<dp[n]<<endl;
    }
  }
  //return 0;*/
  cout<<"Possible"<<endl;
  cout<<n<<" "<<m<<endl;
  for(int i=1; i<=n; i++){
    for(auto e:g[i]){
      cout<<i<<" "<<e.first<<" ";
      if(e.second==-1) cout<<"X"<<endl;
      else if(e.second==-2) cout<<"Y"<<endl;
      else cout<<e.second<<endl;
    }
  }
  cout<<1<<" "<<n<<endl;
	return 0;
}