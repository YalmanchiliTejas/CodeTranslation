#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
  int n;
  string odr;
  while( cin >> n,n )
    {
      int di[6] = {5,4,1,3,6,2};
      int top_sum = 1; 
      while(n--){
	cin >> odr;
	if(odr == "North"){
	  swap(di[0],di[2]);
	  swap(di[2],di[5]);
	  swap(di[4],di[5]);
	  top_sum+=di[2];
	}else if(odr == "East"){
	  swap(di[1],di[2]);
	  swap(di[1],di[3]);
	  swap(di[1],di[4]);
	  top_sum+=di[2];
	}else if(odr == "West"){
	  swap(di[2],di[3]);
	  swap(di[1],di[3]);
	  swap(di[3],di[4]);
	  top_sum+=di[2];
	}else if(odr == "South"){
	  swap(di[0],di[2]);
	  swap(di[0],di[5]);
	  swap(di[0],di[4]);
	  top_sum+=di[2];
	}else if(odr == "Right"){
	  swap(di[0],di[1]);
	  swap(di[1],di[5]);
	  swap(di[3],di[5]);
	  top_sum+=di[2];
	}else if(odr == "Left" ){
	  swap(di[0],di[3]);
	  swap(di[3],di[5]);
	  swap(di[5],di[1]);
	  top_sum+=di[2];
	}
    }
   cout << top_sum << endl;
    }
}