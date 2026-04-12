#include <bits/stdc++.h>
#define rep(i,a,n) for(int (i) = (a);(i) < (n);(i)++)
typedef long long ll;
using namespace std;

int main(){
  	int x,y,z,i = 1;
  	cin >> x >> y >> z;
  
  	while(1){
      if(!(z+i*(y+z)<= x)){
        cout << i-1 << endl;
        return 0;
      }
      i++;
    }
	return 0; 
}