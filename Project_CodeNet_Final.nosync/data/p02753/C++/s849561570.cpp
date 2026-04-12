#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	string s;cin>>s;
  	sort(s.begin(), s.end());
  	if(s[0]==s[2]){				
    	cout<<"No\n";
    } else{
      	cout<<"Yes\n";
    }

	return 0;
}
