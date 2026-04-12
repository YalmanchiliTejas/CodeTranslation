#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	char a,b,c;
	int s=0;
	cin>>a>>b>>c;
	if(a=='A'||b=='A'||c=='A')s++;
	if(a=='B'||b=='B'||c=='B')s++;
	if(s<2)cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}