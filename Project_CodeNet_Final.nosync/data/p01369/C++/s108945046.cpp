#include<iostream>
#include<sstream>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	string in;
	string l="qwertasdfgzxcvb";
	
	while(cin>>in, in!="#"){
		int cnt=0;
		rep(i,in.size()-1){
			if((l.find(in[i])!=l.npos)^(l.find(in[i+1])!=l.npos))cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}