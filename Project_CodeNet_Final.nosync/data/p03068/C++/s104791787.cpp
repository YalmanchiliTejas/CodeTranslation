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
  int n,k;
  string s;
  cin >> n >> s >> k;
  rep(i,n){
    if(s[i]!=s[k-1]){
      cout << "*";
    }else{
      cout << s[i];
    }
  }
  cout << endl;
}
