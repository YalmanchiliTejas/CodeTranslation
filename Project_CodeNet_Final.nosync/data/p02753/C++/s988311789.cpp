#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	int ca =0,cb=0;
	getline (cin,s);
	for(int i=0;i<3;i++){
	    if(s[i]=='A')ca++;
	    else if(s[i]=='B')cb++;
	}
	if(ca*cb)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
