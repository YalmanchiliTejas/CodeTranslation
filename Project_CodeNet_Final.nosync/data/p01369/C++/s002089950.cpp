
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isleft(char c)
{
	string right="qwertasdfgzxcvb";
	return find(right.begin(),right.end(),c)==right.end();
}
int main()
{
	string input;
	while(cin>>input){
		if(input=="#")break;
		bool curleft=isleft(input[0]);
		int ret=0;
		for(int i=1;i<input.size();i++){
			if(isleft(input[i])!=curleft)ret++;
			curleft=isleft(input[i]);
		}
		cout<<ret<<endl;
	}
	return 0;
}