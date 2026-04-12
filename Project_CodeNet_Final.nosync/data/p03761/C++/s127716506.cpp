#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s;
string st;

int main(){
	cin>>n>>s;
	for(int i=0;i<n-1;i++){
		cin>>st;
		string sth;
		for(int j=0;j<s.length();j++){
			for(int k=0;k<st.length();k++){
				if(s[j]!=' '&&s[j]==st[k]){
					sth+=s[j];
					s[j]=' ';
					st[k]=' ';
				}
			}
		}
		s=sth;
	}
	sort(s.begin(),s.end());
	cout<<s<<endl;
	return 0;
}