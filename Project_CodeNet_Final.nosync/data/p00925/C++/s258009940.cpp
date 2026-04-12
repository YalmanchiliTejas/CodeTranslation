#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
using namespace std;
int stoi(string x){stringstream ss;ss<<x;int tmp;ss>>tmp;return tmp;}
string itos(int x){stringstream ss;ss<<x;return ss.str();}
//#define __int64 long long
#define ll __int64 
int main(){
	string n,a,b,c,tmp;
	int a1,a2=0,a3=0;
	cin>>n;
	cin>>a1;
	vector<string>ta,ta2;
	for(int i=0;i<n.size();i++){
	if(n[i]=='*'||n[i]=='+'){
	ta.push_back(tmp);
	if(n[i]=='*')ta.push_back("*");
	if(n[i]=='+')ta.push_back("+");
	tmp.clear();
	}
	else tmp.push_back(n[i]);
	}
	ta.push_back(tmp);
	a2=stoi(ta[0]);
	for(int i=1;i<ta.size();i++){
		if(ta[i]=="+"){
		a2+=stoi(ta[i+1]);
		i++;
		}
		if(ta[i]=="*"){
		a2*=stoi(ta[i+1]);
		i++;
		}
	}
	
	for(int i=0;i<ta.size();i++){
		if(ta[i]=="*"){
		ta[i]=( itos( stoi(ta[i-1])*stoi(ta[i+1]) ) );
		ta.erase(ta.begin()+i+1);
		ta.erase(ta.begin()+i-1);
		i--;
		}
	}
	for(int i=0;i<ta.size();i++){
	if(ta[i]!="+")a3+=stoi(ta[i]);
	}
	if(a1==a2&&a1==a3)cout<<"U";
	else if(a1==a2)cout<<"L";
	else if(a1==a3)cout<<"M";
	else cout<<"I";
	cout<<endl;
	return 0;
}