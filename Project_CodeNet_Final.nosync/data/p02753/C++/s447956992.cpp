// author::devendra parihar
#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main(){
		string s;
		cin>>s;
		bool f=false;
		for(int i=0;i<s.size()-1;i++){
			for(int j=i+1;j<s.size();j++)
			if(s[i]!=s[j]){
				f=true;
			}
		}
		if(f==true) cout<<"Yes";
		else cout<<"No";
		return 0;
}			