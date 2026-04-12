#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	sort(s.begin(),s.end());
	if(s[0]==s[2]){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}