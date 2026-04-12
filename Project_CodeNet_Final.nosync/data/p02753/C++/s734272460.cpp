#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
string s;
set <char> ss;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	ss.insert(s[0]);
	ss.insert(s[1]);
	ss.insert(s[2]);
	if(ss.size()==2){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}