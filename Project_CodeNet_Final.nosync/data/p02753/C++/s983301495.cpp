#include <bits/stdc++.h>
# define ll long long int
using namespace std;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fast();
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]=='A' and s[1]=='B'){
    	cout<<"Yes";
    	return 0;
	}
	else if(s[1]=='A' and s[2]=='B'){
		cout<<"Yes\n";
		return 0;
	}
	else{
		cout<<"No";
	}
}