#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string s;
int main(){
	cin >> n >> s >> k;
	k--;
	for(int i=0;i<n;i++)
		if(s[i]==s[k])cout << s[i];
		else cout << "*";
    return 0;
}