#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;
	string s,w1,w2="";
	cin>>n>>s>>k;
	w1=s.substr(k-1,1);
	for(int i=0;i<s.length();i++){
		if(s.substr(i,1)==w1){
			w2+=s.substr(i,1);
		}else{
			w2+="*";
		}
	}
	cout<<w2<<endl;

	return 0;
}
