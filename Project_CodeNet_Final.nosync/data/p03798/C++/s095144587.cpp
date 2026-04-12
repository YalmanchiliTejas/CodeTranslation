#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long int ll;

char r(char s){
	if(s=='S')return 'W';
	else return 'S';
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n; 
	string s; cin >> s;
	for(int i=0;i<4;i++){
		string t="";
		if(i%2)t+='S';
		else t+='W';
		if(i%3)t+='S';
		else t+='W';
		for(int j=1;j<n-1;j++){
			if(t[j]=='S'){
				if(s[j]=='o'){
					t+=t[j-1];
				}
				else{
					t+=r(t[j-1]);
				}
			}
			else{
				if(s[j]=='o'){
					t+=r(t[j-1]);
				}
				else{
					t+=t[j-1];
				}
			}
		}
		if(t[0]=='S'){
			if(s[0]=='x'&&t[1]==t[n-1])continue;
			if(s[0]=='o'&&t[1]!=t[n-1])continue;
		}
		else{
			if(s[0]=='x'&&t[1]!=t[n-1])continue;
			if(s[0]=='o'&&t[1]==t[n-1])continue;
		}
		if(t[n-1]=='S'){
			if(s[n-1]=='o'&&t[0]!=t[n-2])continue;
			if(s[n-1]=='x'&&t[0]==t[n-2])continue;
		}
		else{
			if(s[n-1]=='o'&&t[0]==t[n-2])continue;
			if(s[n-1]=='x'&&t[0]!=t[n-2])continue;
		}
		cout << t << endl;
		return 0;
	}
	cout << -1 << endl;
}
