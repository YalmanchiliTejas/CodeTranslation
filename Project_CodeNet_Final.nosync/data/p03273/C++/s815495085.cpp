#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)  
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
  int h,w;
  cin>>h>>w;
  int a[h][w];
  REP(i,h){
    string s;
    cin>>s;
    REP(j,w){
      if(s[j]=='.'){
        a[i][j] = 0;
      }else{
        a[i][j] = 1;
      }
    }
  }

  REP(i,h){
    bool b = false;
    REP(j,w){
      if(a[i][j]==1){
        b = true; 
        break;
      }
    }
    if(b==true){
      REP(j,w){
        bool b2 = false;
        REP(k,h){
          if(a[k][j]==1){
            b2 = true;
            break;
          }
        }
        if(b2==true){
          if(a[i][j]==1){
            cout<<"#";
          }else{
            cout<<".";
          }
        }
      }
      cout<<endl;
    }
  }


  return 0;
}