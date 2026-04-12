#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
string s;
regex reg(".*AC.*");
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	puts(regex_match(s,reg) ? "Yes" : "No");
}