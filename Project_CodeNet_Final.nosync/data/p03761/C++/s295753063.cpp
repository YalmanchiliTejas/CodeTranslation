#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i=0; i<n; i++) cin >> s[i];

	for(int i=0; i<n; i++){
		sort(s[i].begin(), s[i].end());
	}

	sort(s.begin(), s.end());

	string res = s[0];
	string tmp = "";
	int tmpi;
	for(int i=1; i<n; i++){
		tmpi = 0;
		tmp = "";
		for(int j=0; j<res.length(); j++){
			for(int k=tmpi; k<s[i].length(); k++){
				if(res[j] == s[i][k]){
					tmpi = k+1;
					tmp.push_back(res[j]);
					break;
				}
			}
		}
		res = tmp;
	}
	cout << res << endl;
}

