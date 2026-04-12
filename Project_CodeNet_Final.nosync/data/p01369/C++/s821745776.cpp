#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string right="yuiophjklnm";
  string s;
  while(true){
      cin>>s;
      if(s=="#") break;
      int res=0,side=0; //???????????????????????????
      for(int i=0;i<11;i++) if(s[0]==right[i]) side=1;
      for(int i=1;i<(int)s.length();i++){
          int tmp=0;
          for(int j=0;j<11;j++) if(s[i]==right[j]) tmp=1;
          if(side==tmp) continue;
          else{
              res++;
              side=tmp;
          }
      }
      cout<<res<<endl;
  }
  return 0;
}