#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    int n,l,r;
    cin >> n >> l >> r;
    if(n==0) return 0;
    vector<int> d(n);
    for(int i=0;i<n;i++) cin >> d[i];
    int count = 0;
    for(int i=l;i<=r;i++){
      bool ok=false;
      for(int j=0;j<n;j++){
	if(i%d[j]==0){
	  if(j%2==0) count++;
	  ok=true;
	  break;
	}
      }
      if(!ok&&n%2==0) count++;
    }
    cout << count << endl;
  }
  return 0;
}

