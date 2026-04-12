#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;
 
int main(){

	int n;
	string s, st;
	cin >> n >> s;
	for(int i=0; i<n-1; i++){
		cin >> st;
		string sth;
		for(int j=0; j<s.length(); j++){
			for(int k=0; k<st.length(); k++){
				if(s[j]!=' ' && s[j]==st[k]){
					sth+=s[j];
					s[j]=' ';
					st[k]=' ';
				}
			}
		}
		s=sth;
	}
	sort(s.begin(), s.end());
	cout << s << endl;

	return 0;
}
