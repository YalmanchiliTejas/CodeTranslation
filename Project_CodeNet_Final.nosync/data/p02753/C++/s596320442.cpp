#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#include<vector>
#define endl "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lb lower_bound
#define ub upper_bound
using namespace std;

int main(){
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A')
		a++;
		else
		b++;
	}
	if(a==s.length() || b==s.length()){
		cout<<"No";
}
else
cout<<"Yes";
return 0;
}