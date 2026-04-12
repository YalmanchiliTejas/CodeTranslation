#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	string *s;
	string ans="";
	cin>>n;
	s= new string[n];
	
	for(int i=0; i<n; i++)	cin>> s[i];

	int alp[n][26];
	for(int i=0; i<n; i++)
		for(int j=0; j<26; j++)
			alp[i][j]=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<s[i].size(); j++){
			int tmp= s[i].at(j)-'a';
			alp[i][tmp]++;
		}
	}
	
	for(int i=0; i<26; i++){
		int times=32767;
		for(int j=0; j<n; j++){
			times= min(times, alp[j][i]);
		}

		for(int j=0; j<times; j++){
			ans+= 'a'+i;	
			
		}
				
	}

	cout<< ans<<endl;

	return 0;	
}