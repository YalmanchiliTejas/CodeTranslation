#include<bits/stdc++.h>
using namespace std;
#define ll  int
#define fr first
#define sc second
#define MAX ((ll)(1e18+100))
#define MOD ((ll)(1e9+7))
#define HS1 ((ll)(137))
#define HS2 ((ll)(1e9+9))
#define ARRS ((ll)(6e5+900))
#define pb push_back
#define mid ((l+r)>>1)
#define PI 3.14159265358979323846

int main(){
	string s;
	ll k=0;
	cin>>s;
	for(int i=0; i<s.size()-1; i++){
		if(s[i]=='A'&&s[i+1]=='C')k=3;

	}
	if(k==3)cout<<"Yes";
	else cout<<"No";
	return 0;
}
