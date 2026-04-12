#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000001

int main(){
	ll n,k;
	string s;
	cin>>n;
	cin>>s;
	cin>>k;
	for(ll i=0;i<n;i++){
		if(s[k-1]!=s[i]){
			s[i]='*';
		}
	}
	cout<<s<<endl;
}
