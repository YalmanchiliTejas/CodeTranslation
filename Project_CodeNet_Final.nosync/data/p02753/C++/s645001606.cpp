#include <bits/stdc++.h>
using namespace std;

int main(){
  string companies;
  cin >> companies;
  int anum = 0;
  for(int i=0; i<companies.size(); i++){
    if(companies.at(i) == 'A'){
    	anum++;
    }
  }
  if( anum == 0 || anum == 3){
    cout << "No" << endl;
  } else {
  	cout << "Yes" << endl;
  }
}