#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int count = 0;
	rep(i,3){
		if(s[i] == 'A') count++;
	}
	if(count==0 || count==3){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
    return 0;
}

