#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool a=false;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='C')a=true;
	}
	if(a==true)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
