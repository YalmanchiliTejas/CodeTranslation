#include<iostream>
using namespace std;

main(){
	string r,g,b,x;
  	cin >> r>>g>>b;
  	x = r+g+b;
  	int i = stoi(x);  
  	if (i%4 ==0){
    	cout<<"YES"<<endl;
    }
  	else{cout<<"NO"<<endl;}
  	
  
  	return 0;

}