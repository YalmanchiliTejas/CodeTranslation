#include<iostream>
#include<sstream>
using namespace std;
int main(){
  	int r,g,b,res;
  	cin>>r>>g>>b;
  	string s;
  	s+='0'+r;
  	s+='0'+g;
  	s+='0'+b;
  	stringstream ss;
  	ss<<s;
  	ss>>res;
  	if(res%4==0) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
	return 0;
}
