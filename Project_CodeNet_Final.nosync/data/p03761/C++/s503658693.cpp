#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000007;

int main(void){
	int alp[50][26] = {{0}}, common[26] = {0};
	int n;
	cin>>n;

	/*for(int i=0;i<26;i++) {
		for(int j=0;j<n;j++) {
			cout<< alp[i][j];
		} cout<<endl;
	}*/
	string alphabet = "zyxwvutsrqponmlkjihgfedcba";
	for(int i=0;i<n;i++) {
		string S;
		cin>>S;

		for(int j=0;j<S.size();j++) {
			alp[i]['z' - S[j]]++;
		}
	}

	/*for(int i=0;i<n;i++) {
		for(int j=0;j<26;j++) {
			cout<<alp[i][j];
		} cout<<endl;
	}*/

	for(int i=0;i<26;i++) {
		int tmp = INF;
		for(int j=0;j<n;j++) {
			tmp = min(tmp, alp[j][i]);
		}
		common[i] = tmp;
	}

	//for(int i=0;i<26;i++) cout<<common[i]<<endl;

	string ans;
	for(int i=25;i>=0;i--) {
		for(int j=0;j<common[i];j++) {
			ans += alphabet[i];
		}
	}
	//cout<<endl;

	cout<< ans <<endl;

	return 0;
}