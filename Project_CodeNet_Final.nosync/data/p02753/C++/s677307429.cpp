#include<iostream>
#include<string>
using namespace std;

int main(){
	string S;
  	bool T=false;
  	cin>>S;
  	for(int i=1;i<3;i++){
		if(S[i-1]!=S[i]){
          T=true;
          break;
        }
    }
  	if(T){
		cout<<"Yes";
    }
  	else{
		cout<<"No";
    }
  	return 0;
}