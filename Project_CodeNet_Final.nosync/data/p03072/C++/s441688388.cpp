#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, c = 1;
  cin >> n;
  vector <int> h(n);
  for (int i = 0; i < n; ++i){
	cin >> h[i];
  }
  int m = h[0];
  for (int i = 1; i < n; ++i){
	if (h[i] >= m){
		++c;
		m = h[i];
	}
  }
  cout << c << "\n";
return 0;
}