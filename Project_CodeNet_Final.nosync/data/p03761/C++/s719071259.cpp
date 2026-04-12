
#include <iostream>
using namespace std;


int main(){
	int letter[26]={},memo[26]={};
	int n;
	string input;
	
	for(int i=0;i<26;i++){
		letter[i]=1000;
	}
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> input;
		for(int j=0;j<input.size();j++){
			memo[input[j]-'a']++;
		}
		for(int j=0;j<26;j++){
			letter[j]=min(letter[j],memo[j]);
			memo[j]=0;
		}
		
	}
	
	string answer={};
	for(int i=0;i<26;i++){
		for(int j=0;j<letter[i];j++){
			char a='a'+i;
			answer+=a;
		}
	}
	cout << answer << endl;
	
	return 0;
}
