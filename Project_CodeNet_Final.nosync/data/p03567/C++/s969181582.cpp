#include"bits/stdc++.h"
using namespace std;
int main(){
	string s;
	cin>>s;
	bool ch=false;
	for(int i=0;i!=s.size()-1;++i){
		if(s.substr(i,2)=="AC")
			ch=true;
	}
	cout<<(ch ? "Yes":"No");
}