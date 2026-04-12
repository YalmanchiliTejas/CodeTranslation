#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int count = 0;
  vector<int> h(n);

  for(int i=0;i<n;i++){
  	cin >> h.at(i);
  }
  for(int i=0;i<n;i++){
  	for(int j=0;j<=i;j++){
  		if(i == j){
  			count++;
  			break;
  		}
  		else if(h.at(j) <= h.at(i))
  			continue;
  		else
  			break;
  	}
  }
  cout << count << endl;
}