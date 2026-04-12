#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std; 

string list = "yuiophjklnm";

int main()
{
	string in;
	int l, count;
	int p; //0,1,2

 while(cin >> in){
	if(in=="#"){return 0;}
	count=0; p=0;
	l = in.length();
	for(int i=0; i<l; i++){
		if( list.find( in.substr(i,1) ) != string::npos){
			if(p==1){count++;}
			p=2;
		}
		else{
			if(p==2){count++;}
			p=1;
		}
	}
	cout << count << endl;
 }
}