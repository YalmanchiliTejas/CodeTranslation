#include<iostream>
#include<string>
using namespace std;

int main(){
	char c;
	cin>>c;
	string check=(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')?"vowel":"consonant";
	cout<<check<<endl;
	return 0;
}