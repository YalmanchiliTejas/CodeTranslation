#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	vector<string> a;
	string s;
	while(cin>>s)
		if(s!=string(w,'.'))
			a.push_back(s);
	for(int j=0;j<a[0].size();j++){
		bool e=true;
		for(int i=0;i<a.size();i++)
			e&=a[i][j]=='.';
		if(e){
			for(int i=0;i<a.size();i++)
				a[i].erase(j,1);
			j--;
		}
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++)
			cout<<a[i][j];
		cout<<endl;
	}
}
