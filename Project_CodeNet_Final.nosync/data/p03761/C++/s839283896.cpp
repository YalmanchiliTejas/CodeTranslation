#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;

char a[26];
string t;
int main(){
	ll n;
	cin>>n;
	string s[n];
	
	for(ll i=0; i<n; i++){
		cin>>s[i];
	}
	
	for (char c = 'a'; c <= 'z'; c++)
 	   a[c - 'a'] = c;
	
	for(int i=0; i<26; i++){
		bool ok=true;
		for(ll j=0; j<n; j++){
			
			if(s[j].find(a[i])== string::npos){
				ok=false;
				break;
			}
		}
		ll mn=1e18;
		if(ok==true) {
		
			for(ll j=0; j<n; j++){
				ll ans=0;
				for(ll k=0; k<s[j].size(); k++){
					if(s[j][k]==a[i]) ans++;
				}
				mn=min(mn,ans);
			}
			for(ll h=1; h<=mn; h++){
				t +=a[i];
			}
		}
	}
	cout<<t<<endl;
	
}
