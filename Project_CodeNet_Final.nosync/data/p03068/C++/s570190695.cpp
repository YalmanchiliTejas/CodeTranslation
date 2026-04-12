#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
	int n;
    cin >>n;
	string s;
    cin >>s;
	int k; 
    cin >>k;
	for(int j=0;j<s.size();j++){
		if(s[k-1]!=s[j])s[j]='*';
	}
	cout << s << endl;
}
