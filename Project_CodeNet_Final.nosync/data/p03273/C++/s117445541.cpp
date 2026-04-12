#include<bits/stdc++.h>
using namespace std;
string s;
vector<string>str;
string c[103];
int n,w;
int main(){
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>s;
		bool can=0;
		for(int j=0;j<w;j++)
			if(s[j]=='#')
				can=1;
		if(can)str.push_back(s);
	}
	for(int i=0;i<w;i++)
	{
		bool can=0;
		for(int j=0;j<str.size();j++)
			if(str[j][i]=='#')
				can=1;
		if(can)
			for(int j=0;j<str.size();j++)
				c[j]+=str[j][i];
	}
	for(int i=0;i<str.size();i++)
		cout<<c[i]<<endl;
}