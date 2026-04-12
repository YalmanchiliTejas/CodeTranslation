#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int num;
	cin>>num;

	int L=str[0]-'0';
	for(int i=1;i<str.length();i+=2){
		if(str[i]=='+') L+=str[i+1]-'0';
		else if(str[i]='*') L*=str[i+1]-'0';
	}

	str+='+';
	vector< int > vc;
	bool f=0;
	for(int i=1;i<str.length();i+=2){
		if(str[i]=='+'){
			if(!f) vc.push_back(str[i-1]-'0');
			f=0;
		} else if(str[i]=='*'){
			if(!f){
				vc.push_back((str[i-1]-'0')*(str[i+1]-'0'));
				f=1;
			} else if(f){
				int tmp=vc.back();
				vc.pop_back();
				vc.push_back(tmp*(str[i+1]-'0'));
			}			
		}
	}

	int M=0;
	for(int i=0;i<vc.size();i++) M+=vc[i];

	if(num==M && num==L) cout<<"U\n";
	else if(num==L) cout<<"L\n";
	else if(num==M) cout<<"M\n";
	else cout<<"I\n";
	return 0;
}
