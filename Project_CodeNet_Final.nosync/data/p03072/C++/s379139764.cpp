#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	cin >> N;
  
  	vector<int> vec(N);
  
  	for(int i = 0; i < N; i++) {
    	cin >> vec.at(i);
    }
  	
  	int sum = 0;
  
  	for(int i = 0; i < N;i++) {
      bool can = true;
    	for(int j = 0; j < i; j++) {
        	if(vec.at(j) > vec.at(i)) {
              can = false;
              break;
        	}
        }
      if(can)
      	sum++;
    }
  
  	cout << sum << endl;
}