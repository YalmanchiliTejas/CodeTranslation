#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s; 
	cin>>s; 
	int A = 0;
	int B = 0;
	for(int i=0;i<3;i++){
		if(s[i]=='A')A++;
		if(s[i]=='B')B++;
	}
	if(A and B)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
