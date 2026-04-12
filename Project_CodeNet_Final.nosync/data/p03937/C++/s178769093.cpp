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
const int MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w,res=0;
  cin >> h >> w;
  char memo;
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      cin >> memo;
      if(memo=='#') res++;
    }
  }
  if(res==h+w-1) cout <<  "Possible" << endl;
  else cout << "Impossible" << endl;
}