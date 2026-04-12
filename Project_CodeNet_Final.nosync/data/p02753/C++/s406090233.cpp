#include <bits/stdc++.h>
#define ll long long
#define MAX 200005

using namespace std;

ll a[MAX];

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
	string s;
	cin >> s;
	ll i,j,t,k;
	ll ca=0,cb=0;
	for(i=0;i<s.size();i++){
		if(s[i]=='A'){
			ca++;
		}
		else if(s[i]=='B'){
			cb++;
		}
	}
	if(ca!=0&&cb!=0){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
    return 0;
}
