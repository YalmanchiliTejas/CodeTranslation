#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for(auto & v : a) cin >> v;
  for(int i = 0; i < n; i++){
  	int tot = 0;
    for(int j = 0; j < m; j++) tot += a[i][j] == '#';
    if(tot){
    	for(int j = 0; j < m; j++){
        	int ntot = 0;
          	for(int k = 0; k < n; k++) ntot += a[k][j] == '#';
          	if(ntot) cout << a[i][j];
        }
      	cout << endl;
    }
  }
  return 0;
}