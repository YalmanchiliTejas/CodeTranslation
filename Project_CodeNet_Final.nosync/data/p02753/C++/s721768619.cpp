#include <bits/stdc++.h>
#define vi vector<int>
#define Vi vector<vector<int>>
#define ll long long
#define P pair<int,int>
#define vp  vector<P>
#define mod 1000000009
using namespace std;
int main(){
	string S;
	cin>>S;
	if((S[0]=='A' || S[1]=='A' || S[2]=='A') && (S[0]=='B' || S[1]=='B' || S[2]=='B'))
		cout<<"Yes\n";
	else
		cout<<"No\n"; 
	return 0;
}