#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define rep(i,m,n) for(int i = (m);i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
#define Vec(a) vector <int> a
const int INF = 1 << 20;
const int MOD = 1e9+7;





int main(){
  string s;
  cin >> s;
  REP(i,s.size()-1){
    if(s[i] == 'A' && s[i+1] == 'C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
