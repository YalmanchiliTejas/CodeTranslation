#include <bits/stdc++.h>
using namespace std;

string s;
int n,k,m;

int main(){
	cin>>n;
	cin>>s;
	cin>>k;
	for(int i = 0;i <= n ;i ++){
		if(s[i - 1] != s[k - 1]){
			s[i - 1] = '*';
		}
	}
	cout<<s<<endl;
}
