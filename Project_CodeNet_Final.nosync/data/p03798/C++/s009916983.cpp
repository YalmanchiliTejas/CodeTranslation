#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  int N;
  string S,res="";
  cin >> N;
  cin >> S;
  REP(i,2){
    REP(j,2){
      res = "";
      if(i == 0){
        res += "S";
      }else{
        res += "W";
      }
      if(j == 0){
        res += "S";
      }else{
        res += "W";
      }
      for(int k=1;k<N-1;k++){
        if(res[k] == 'S'){
          if(S[k] == 'o'){
            res.push_back(res[k-1]);
          }else{
            res.push_back(res[k-1] == 'S' ? 'W' : 'S');
          }
        }else{
          if(S[k] == 'x'){
            res.push_back(res[k-1]);
          }else{
            res.push_back(res[k-1] == 'S' ? 'W' : 'S');
          }
        }
      }
      int f=1;
      REP(i,N){
        if(S[i] == 'o'){
          if(res[i] == 'S'){
            if(res[(N+i-1)%N] != res[(N+i+1)%N])
              f=0;
          }else{
            if(res[(N+i-1)%N] == res[(N+i+1)%N])
              f=0;
          }
        }else{
          if(res[i] == 'S'){
            if(res[(N+i-1)%N] == res[(N+i+1)%N])
              f=0;
          }else{
            if(res[(N+i-1)%N] != res[(N+i+1)%N])
              f=0;
          }
        }
      }
      if(f){
        cout << res << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

