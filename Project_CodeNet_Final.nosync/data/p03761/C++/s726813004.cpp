#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main() {
	int N;
	cin>>N;
	vector<string>S(N);
	vector<vector<int>>C(26,vector<int>(N));
	vector<int>ans(26);
	for(int i=0;i<N;i++)
	{
		cin>>S[i];
		for(int j=0;j<S[i].size();j++)C[S[i][j]-'a'][i]++;
	}
	for(int i=0;i<26;i++)
	{
		int mini=51;
		for(int j=0;j<N;j++){
			mini=min(mini,C[i][j]);
		}
		ans[i]=mini;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<ans[i];j++)cout<<char(i+'a');
	}
}