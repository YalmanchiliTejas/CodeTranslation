#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n)(int i = 1; i <= n ; i++)

signed main(){
	char a;
	bool ans  = false;
	cin>>a;
	
	if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')ans = true;
	
	cout<<(ans?"vowel":"consonant")<<endl;
	return 0;
}