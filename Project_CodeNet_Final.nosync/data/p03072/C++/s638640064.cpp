#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
vector<int> h(n);
rep(i,n) cin >> h.at(i);
int ans  = 1;
int maxHeight = h.at(0);
for(int i = 1; i < n; i++){
  if(h.at(i) >= maxHeight){
    ans++;
    maxHeight = h.at(i);
  }
}
cout << ans << endl;
}
  
