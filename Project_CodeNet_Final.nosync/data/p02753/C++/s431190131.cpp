#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	string s;
	cin >> s;

	ll cnt1 = 0,cnt2 = 0;
	for(ll i=0;i<3;i++){
		if(s[i]=='A'){
			cnt1++;
		}
		else{
			cnt2++;
		}
	}

	if(cnt1 == 0 || cnt2 == 0){
		cout << "No\n";
	}
	else{
		cout << "Yes\n";
	}
}