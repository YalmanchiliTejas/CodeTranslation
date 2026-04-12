#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define init(c) memset(c,0,sizeof c)
typedef long long ll;
const int N=20000005;
int n,k,x,t,a,b;
string s;
vector<int>v;
int main(){

	cin >> s;
	if(s[0] == s[1] && s[1] == s[2]){
		cout << "No";
	}else{
		cout << "Yes";
	}
	return 0;
}