#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) (x.begin()),(x.end())
#define sz(x)  ((ll)x.size())
#define FAST_IO ios_base :: sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
void tokenize(string str,const char delim,vector<string> & res){
	stringstream p(str);
	string token;
	while(getline(p,token,delim)){
		res.push_back(token);
	}
	return;
}

// Your workSpace ...

	
	
ll N;	
void test_case(){
	cin >> N;
	if(N >= 30) cout << "Yes" << endl;
	else cout << "No" << endl; 
}
	





int main(){
	FAST_IO;
	int tt;
	//cin>>tt;
	tt = 1;
	while(tt--){
		test_case();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
