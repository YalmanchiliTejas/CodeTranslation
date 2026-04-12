#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z,i=1;
  	cin >> x >> y >> z;
  	for(;;i++){
  		if(z*(i+1)+y*i>x){
      		break;
    	}
    }
    cout << i-1 << endl;
}