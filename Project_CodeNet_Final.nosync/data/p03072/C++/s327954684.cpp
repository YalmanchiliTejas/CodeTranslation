#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MOD 1000000007

int n,H[25],ans;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> H[i];
    if(i==0){
      ans++;
      continue;
    }
    for(int j = 0; j <i; j++){
      if(H[i] >= H[j]){
        if(i-1==j) ans++;
      }else{
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}