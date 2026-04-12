#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<char>v={'a','e','i','o','u'};
	char c;
	cin>>c;
	v.push_back(c);
	int i=0;
	while(v.at(i)!=c)++i;
	if(i!=v.size()-1)cout<<"vowel\n"s;
	else cout<<"consonant\n"s;
}