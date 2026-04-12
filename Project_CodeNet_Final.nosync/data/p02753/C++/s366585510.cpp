#include<bits/stdc++.h>
using namespace std;
int main(){
	bool b=false,ab=false;
	for(int i=0;i<3;i++){
		char a;
		cin>>a;
		if(a=='A'){
			ab=true;
		}else if(a=='B'){
			b=true;
		}
	}
	if(b&&ab){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}