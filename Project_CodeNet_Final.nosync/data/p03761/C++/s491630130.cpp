#include <bits/stdc++.h>
using namespace std;

string alph="abcdefghijklmnopqrstuvwxyz";
map<char, int> M;
int alphc[27][51];

int main(){
	int x=0;
	for(char c : alph){
		M[c]=x;
		x++;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(char c : s){
			alphc[M[c]][i]++;
		}
	}
	
	for(int i=0;i<26;i++){
		alphc[i][50]=51;
		for(int j=0;j<n;j++){
			alphc[i][50]=min(alphc[i][50],alphc[i][j]);
		}
	}
	
	for(int i=0;i<26;i++){
		while(alphc[i][50]--){
			cout<<alph[i];
		}
	}
	cout<<endl;
}