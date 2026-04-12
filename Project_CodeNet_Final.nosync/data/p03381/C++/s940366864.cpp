#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<int> x(N);
  for(int i=0;i<N;i++) cin >> x[i];
  vector<int> a = x;
  sort(a.begin(), a.end());
  int midleft = a[N/2 - 1];
  int midright = a[N/2];
  for(int i=0;i<N;i++){
    if(x[i] <= midleft) cout << midright << endl;
    else cout << midleft << endl;
  }
}