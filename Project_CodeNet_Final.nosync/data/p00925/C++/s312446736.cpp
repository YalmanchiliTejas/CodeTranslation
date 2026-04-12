#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
typedef long long ll;
string s;
int n;
ll x;
ll term(int &it){
	ll now=s[it]-'0';
	it++;
	while(s[it]=='*'){
		it++;
		now*=(s[it]-'0');
		it++;
	}
	return now;
}
bool ism(int &it){
	ll now=term(it);
	while(s[it]=='+'){
		it++;
		ll l=term(it);
		now+=l;
	}
	return now==x;
}
bool isl(int it){
	ll now=s[it]-'0';
	it++;
	while(s[it]=='*'||s[it]=='+'){
		if(s[it]=='+'){
			it++;
			now+=(s[it]-'0');
			it++;
		}
		if(s[it]=='*'){
			it++;
			now*=(s[it]-'0');
			it++;
		}
	}
	return now==x;
}
int main(){
	cin>>s>>x;
	s+='$';
	n=s.size();
	int it=0;
	bool m=ism(it);
	it=0;
	bool l=isl(it);
	if(m&l) cout<<"U\n";
	if(m&!l) cout<<"M\n";
	if(!m&&l) cout<<"L\n";
	if(!m&&!l) cout<<"I\n";
}