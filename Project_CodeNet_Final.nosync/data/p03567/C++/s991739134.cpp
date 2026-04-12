#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	string s;
	cin>>s;
	bool ok=false;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='C')ok=true;
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}