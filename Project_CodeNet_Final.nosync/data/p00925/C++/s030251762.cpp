#include<iostream>
#include<string>

using namespace std;

int main(){

	string exp;

	int ans;
	int ma,la;
	int mt;

	cin>>exp;
	cin>>ans;

	if(exp.size()==1){
		if(exp[0]-'0'==ans) cout<<"U"<<endl;
		else cout<<"I"<<endl;
		return 0;
	}

	la=(exp[1]=='+')?exp[0]-'0'+exp[2]-'0':(exp[0]-'0')*(exp[2]-'0');
	for(int i=3;i<exp.size();i+=2){
		if(exp[i]=='+') la+=exp[i+1]-'0';
		else la*=(exp[i+1]-'0');
	}

	if(exp[1]=='+'){
		ma=exp[0]-'0';
		mt=-1;
	}
	else{
		ma=0;
		mt=exp[0]-'0';
	}

	for(int i=2;i<exp.size()-1;i+=2){
		if(exp[i+1]=='*'){
			if(mt==-1) mt=exp[i]-'0';
			else mt*=(exp[i]-'0');
		}
		else{
			if(mt!=-1){
				ma+=(mt*(exp[i]-'0'));
				mt=-1;
			}
			else ma+=(exp[i]-'0');
		}
	}
	if(mt!=-1){
		ma+=(mt*(exp[exp.size()-1]-'0'));
		mt=-1;
	}
	else ma+=(exp[exp.size()-1]-'0');

	if(ans==ma&&ans==la) cout<<"U"<<endl;
	else if(ans==ma) cout<<"M"<<endl;
	else if(ans==la) cout<<"L"<<endl;
	else cout<<"I"<<endl;

	return 0;
}