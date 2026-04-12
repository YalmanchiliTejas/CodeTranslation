#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
int n;

int main(){
  auto dmy = scanf("%d", &n);
  vector<ll> data(n);
  for(int i=0; i<n; i++) dmy = scanf("%lld", &data[i]);
  
  multiset<ll> s;
  for(int i=n-1; i>=0; i--){
    auto iter = s.insert(data[i]);
    if(i==n-1) continue;
    auto last = s.end();
    last--;
    if(iter != last){
      iter++;
      s.erase(iter);
    }
  }
  printf("%d", s.size());
  return 0;
}