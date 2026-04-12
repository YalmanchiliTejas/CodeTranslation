#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	int n,min;
	cin >> n;
	string S[n];
	int count[n][26]={};
	int i,j,flag,temp;
	for(i=0;i<n;i++)cin >> S[i];
	for(i=0;i<n;i++){
		temp = S[i].size();
		for(j=0;j<temp;j++){
			count[i][S[i][j]-'a']++;
		}
	}
	for(j=0;j<26;j++){
		min = 51;
		for(i=0;i<n;i++){
			min = std::min(min,count[i][j]);
		}
		for(i=0;i<min;i++){
			printf("%c",j+'a');
		}
	}
	return 0;
}