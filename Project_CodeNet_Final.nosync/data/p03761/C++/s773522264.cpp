#include<bits/stdc++.h>
using namespace std;


int B[26];

int main(){
	int n;
	string s;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		int vis[26]={0},A[26]={0};
		for(int j=0;j<s.size();j++){
			if(!vis[s[j]-'a']) A[s[j]-'a']++;
		}
		if(i==0){
			for(int j=0;j<26;j++){
				B[j]=A[j];
			}
		}
		else{
			for(int j=0;j<26;j++){
				B[j]=min(A[j],B[j]);
			}
		}
	}
	
	
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(B[s[i]-'a']){
			cout << s[i];
			B[s[i]-'a']--;
		}
	}
	cout << endl;
    return 0;
}