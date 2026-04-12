#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	string s; cin>>s;
	char c=s[0];
	if(c==s[1] && c==s[2]) cout<<"No";
	else cout<<"Yes";
	return 0;
}
