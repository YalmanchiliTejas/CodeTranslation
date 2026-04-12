#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string n;
int main(){
	cin>>n;
	int ln=n.size(),i=0;
	while(i<ln){
		if(n[i]=='A'){
			if(n[i+1]=='C'){
				cout<<"Yes"<<endl;
				return 0;
			}
			else if(n[i+1]=='A') i++;
				else i+=2;
		}
		else i++;
	}
	cout<<"No"<<endl;
	return 0;
}