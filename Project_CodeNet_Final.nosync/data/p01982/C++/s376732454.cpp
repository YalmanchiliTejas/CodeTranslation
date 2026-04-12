#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
  int n,l,r;
  while(cin >> n >> l >> r && n!=0 && l!=0 && r!=0){
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    int num=0;
    for(int i=l;i<=r;++i){
      int flag=0;
      for(int j=0;j<n;++j){
	if(i%a[j]==0) {
	  flag++;
	  if((j+1)%2==1) num++;
	  break;
	}
      }
      if(flag==0 && n%2==0) num++;
    }
    cout << num << endl;
  }

  
  return 0;
}

