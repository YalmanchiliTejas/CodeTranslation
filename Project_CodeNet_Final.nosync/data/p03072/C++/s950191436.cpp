#include <iostream>
using namespace std;

int main(){
	int n;
  	cin >> n;
  	int mt[n];
  	
  	for(int i=0; i<n; i++){
      cin >> mt[i];
    }
  
  	int cnt = 0, mx=0;
  	for(int i=0; i<n; i++){
      	if(mt[i] >= mx) cnt++;   	
		mx = max(mt[i], mx);
    }
	
  	cout << cnt << endl;
  	
	return 0;
}