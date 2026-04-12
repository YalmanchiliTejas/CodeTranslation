#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int h,w;
	cin>>h>>w;
	vector<string>ban;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		bool flag=false;
		for(int j=0;j<w;j++)
			if(s[j]=='#')flag=true;
		if(flag)ban.push_back(s);
	}
	vector<int>yoko;
	for(int i=0;i<w;i++){
		bool flag=false;
		for(int j=0;j<ban.size();j++)
			if(ban[j][i]=='#')flag=true;
		if(flag)yoko.push_back(i);
	}
	for(int i=0;i<ban.size();i++){
		for(int j=0;j<w;j++){
			if(find(yoko.begin(), yoko.end(), j)!=yoko.end())cout<<ban[i][j];
		}
		cout<<endl;
	}
	return 0;
}