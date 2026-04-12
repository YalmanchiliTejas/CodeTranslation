#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

bool vowel(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
		 || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}

void solve(){
	char c;
	cin>>c;
	if(vowel(c)){
		cout<<"vowel"<<endl;
	}
	else{
		cout<<"consonant"<<endl;
	}
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
