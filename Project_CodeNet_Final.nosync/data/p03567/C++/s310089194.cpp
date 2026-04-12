#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size()-1;
	bool flg=false;
	rep(i,k){
		if(s[i]=='A'&&s[i+1]=='C') flg=true;
	}
	cout<<(flg?"Yes":"No")<<endl;
}