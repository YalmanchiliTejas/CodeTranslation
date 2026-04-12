#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; string s; int k;
	cin>>n>>s>>k;

	char c=s[k-1];
	for(auto& e:s)
		if(e!=c)e='*';
	cout<<s<<endl;

	return 0;
}