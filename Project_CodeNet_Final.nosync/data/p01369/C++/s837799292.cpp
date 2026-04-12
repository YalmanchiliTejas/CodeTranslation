#include<iostream>
#include<string>
using namespace std;
 int ora(char x){
	if(x=='y'||x=='u'||x=='i'||x=='o'||x=='p'||x=='h'||x=='j'||x=='k'||x=='l'||x=='n'||x=='m'){return 1;}
	return 0;
}
int main(){
	string s;
	while(true){
	cin>>s;
	if(s=="#")break;
	int cnt=0;
	bool flag;
	if(ora(s[0]))flag=true;
	else flag=false;
	for(int i=0;i<s.size();i++){
		if(flag!=ora(s[i]))cnt++;
		flag=ora(s[i]);
	}
	cout<<cnt<<endl;
	}
	return 0;
}