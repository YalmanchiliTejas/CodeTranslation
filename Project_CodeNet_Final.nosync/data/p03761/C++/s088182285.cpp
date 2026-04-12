#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {
  int n;
  string s[55];
  cin>>n;
  REP(i,0,n){
    cin>>s[i];
    sort(s[i].begin(), s[i].end());
  }

  int d[50][26];
  REP(i,0,n)REP(j,0,26) d[i][j] = 0;
  REP(i,0,n){
    REP(j,0,s[i].size()){
      d[i][s[i][j] - 'a']++;
    }
  }

  int minnum[26] = {};
  REP(i,0,26){
    int tmp = 10000;
    REP(j,0,n){
      tmp = min(tmp, d[j][i]);
    }
    minnum[i] = tmp;
  }


  /////

  string ans = "";
  REP(i,0,26){
    int m = min(d[0][i], minnum[i]);
    string alph[26]={"a","b","c","d","e","f","g","h","i","j",
                     "k","l","m","n","o","p","q","r","s","t",
                     "u","v","w","x","y","z"};
    REP(j,0,m) ans += alph[i];
  }

  cout<<ans<<endl;

/*
  string ans = "";

  REP(l,0,s[0].size()){
    REP(r,l,s[0].size()){

      int diff = r-l;
      string subs = s[0].substr(l,diff);
      int cnt = 0;

      //test
      cout<<"subs: "<<subs<<endl;

      REP(i,1,n){

        bool flag = false;
        REP(tl,0,s[i].size()){
          REP(tr,tl,s[i].size()){
            if(tr < s[i].size()){
              int tdiff = tr - tl;
              string tsubs = s[i].substr(tl,tdiff);
              if(subs == tsubs){
                flag = true;
                cnt++;
                break;
              }
            }
          }
          if(flag) break;
        }
      }
      //test
      cout<<"cnt ---> "<<cnt<<endl;

      if(cnt == n-1 && ans.size() < subs.size()){
        ans = subs;
      }
    }
  }

  cout<<ans<<endl;
*/


  return 0;
}
