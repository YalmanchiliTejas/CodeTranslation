//templates
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(x) (x).begin(),(x).end()
#define sort_key(struct_name,key_name) [](const struct_name &x, const struct_name &y){return x.key_name < y.key_name;}
#define pb(x) push_back(x)
typedef long long ll;
using namespace std;

//main
int main(){
  int N; cin >> N;
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  int ans = 1;
  for(int i=1; i<N; i++){
    if(H[i] >= *max_element(H.begin(),H.begin()+i)) ans += 1;
  }
  cout << ans << endl;
}