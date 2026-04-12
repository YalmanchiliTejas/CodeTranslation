#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){
	
	int n; cin >> n;
	
	string s[n];
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	
	vector<char> vc;
	set<char> st;
	map<char, int> mp, mptemp;
	for(int i=0; i<s[0].size(); i++){
		mp[s[0][i]]++;
		st.insert(s[0][i]);
	}
	for(auto x : st){
		vc.push_back(x);
	}
	
	for(int i=1; i<n; i++){
		mptemp.clear();
		for(int j=0; j<s[i].size(); j++){
			mptemp[s[i][j]]++;
		}
		for(int j=0; j<vc.size(); j++){
			mp[vc[j]] = min(mp[vc[j]], mptemp[vc[j]]);
		}
	}
	
	string anstemp;
	for( auto x : mp ){
		for(int i=0; i<x.second; i++){
			anstemp += x.first;
		}
	}
	
	int length = anstemp.size();
	if(length == 0){
		cout << "";
	}
	else{
		char ans[length];
		for(int i=0; i<length; i++){
			ans[i] = anstemp[i];
		}
		
		sort(ans, ans+length);
		
		for(int i=0; i<length; i++){
			cout << ans[i];
		}
	}
	
	return 0;
}