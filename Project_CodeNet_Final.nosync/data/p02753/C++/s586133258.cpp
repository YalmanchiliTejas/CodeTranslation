#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
 
#define pb 					push_back
 
template<typename T,typename S>
ostream& operator <<(ostream& os, pair<T, S> input) {
	os<<"("<<input.first<<", "<<input.second<<")";
	return os;
}
 
template<typename T>
ostream& operator <<(ostream& os, vector<T> input) {
	for(auto t: input)
		os << t <<"\n";
 
	return os;
}
 
 
template<typename T>
ostream& operator <<(ostream& os, set<T> input) {
	for(auto t: input)
		os << t <<"\n";
 
	return os;
}

int main() {

	string s;
	cin >> s;

	for(int i =1; i<(int)s.size(); i++) {
		if(s[i]!=s[i-1]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}