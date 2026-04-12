#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;

  cin >> n;

  vector<int> a(n);
  
  for(int i = 0;i < n;++i)
	cin >> a[i];

  for(int i = 100;i >= 0;--i){
	int sum = 0;
	for(int j = 0;j < n;++j){
	  sum += a[j];
	  sum -= i;
	  if(sum < 0)
		break;
	}
	if(sum >= 0){
	  cout << i << endl;
	  break;
	}
  }

}

