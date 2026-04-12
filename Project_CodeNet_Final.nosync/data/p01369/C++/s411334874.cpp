#include<iostream>
#include<string>
using namespace std;

int main(){
	string s,r="yuiophjklnm";
	int a,b,c;
	while(cin>>s,s[0]!='#'){
		a=-1;
		c=0;
		for(int i=0;i<s.size();i++){
			b=r.find(s[i],0)==string::npos;
			c+=a!=b;
			a=b;
		}
		cout<<c-1<<endl;
	}
	return 0;
}