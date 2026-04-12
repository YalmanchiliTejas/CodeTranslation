#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n;
string str[55];
int mat[55][30];

int main()
{
	IO
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>str[i];
		for(int j = 0; j < int(str[i].size()); ++j){
			mat[i][int(str[i][j]-'a')]++;
		}
	}
	
	for(int i = 0; i < 26; ++i){
		int mini = INT_MAX;
		for(int j = 0; j < n; ++j){
			mini = min(mini,mat[j][i]);
		}
		while(mini--){
			cout<<char(i+'a');
		}
	}
	cout<<endl;

	return 0;
}