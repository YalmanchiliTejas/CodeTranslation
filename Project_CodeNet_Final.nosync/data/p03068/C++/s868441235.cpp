#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9


int main(){
	int n;
	string s;
	int k;
	cin>>n>>s>>k;
	for(int i=0;i<n;i++){
		if(s[i] == s[k-1]){
			cout<<s[i];
		}else{
			cout<<'*';
		}
	}
	cout<<endl;


	return 0;
}
