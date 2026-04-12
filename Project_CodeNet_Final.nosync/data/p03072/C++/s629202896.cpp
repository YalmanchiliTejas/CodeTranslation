#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n  ;
  
  int h;
  cin >> h;
  int m=h;
  int r=1;
  for(int i=1;i<n;i++){
       cin >> h;
       if(h>=m){
	        r++;
			m=h;
	   }
  
  }
  cout <<  r<< endl;
}
