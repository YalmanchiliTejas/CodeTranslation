#include<bits/stdc++.h>
using namespace std;

int main(){
	string s="aeiou"s;
	char c;
	cin>>c;
	s+=c;
	int i=0;
	while(s.at(i)!=c)++i;
	if(i!=s.size()-1)cout<<"vowel\n"s;
	else cout<<"consonant\n"s;
}