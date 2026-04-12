#include <iostream>

using namespace std;

int main (){
	string s;
	cin>>s;
	int tr=0;
	for(int i=0;i<2;i++){
		if(s[i]!=s[i+1]) tr=1;
	}
	if(tr) cout<<"Yes";
	else cout<<"No";





return 0;
}

