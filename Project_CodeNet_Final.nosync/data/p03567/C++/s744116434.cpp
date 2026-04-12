#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (2000000000)
#define MOD (1000000007)
#define PI (acos(-1))

int main(){
  string s;
  cin >> s;
  rep(i,s.size()-1){
    if(s[i]=='A'&&s[i+1]=='C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}