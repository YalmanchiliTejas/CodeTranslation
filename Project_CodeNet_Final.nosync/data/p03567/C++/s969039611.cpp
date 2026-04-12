#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b,c;
  cin >> a;
  
  for(int i =0; i<a.length()-1;i++){
	if(a.substr(i,2)=="AC"){
		cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" <<endl;
   return 0;
}
