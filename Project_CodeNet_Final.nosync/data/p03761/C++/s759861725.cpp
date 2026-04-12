#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(26,0));
	
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			a[i][int(s[j]-'a')]++;
		}
	}
	
	vector<int> check(26,0);
	int now;
	for(int i=0;i<26;i++){
		now=INF;
		for(int j=0;j<n;j++){
			check[i]=min(now,a[j][i]);
			now=check[i];
		}
	}
	
	
	for(int i=0;i<26;i++){
		if(check[i]==0)continue;
		for(int j=0;j<check[i];j++){
			cout << (char)(i+'a');
		}
	}
	cout << endl;

	return 0;
}
