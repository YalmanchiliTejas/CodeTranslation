#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main()
{
    string c;
	s.insert("a");s.insert("e");s.insert("i");s.insert("o");s.insert("u");
	cin>>c;
	if(s.find(c)!=s.end()) cout<<"vowel"<<endl;
	else cout<<"consonant"<<endl;
	return 0;
}
