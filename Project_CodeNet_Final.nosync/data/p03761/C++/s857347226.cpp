#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()

map<char,int> m;
int32_t main(){
	int n;
	cin>>n;
	string s;
	for(char c='a';c<='z';c++){
		m[c]=1000000;
	}
	while(n--){
		cin>>s;
		for(char c='a';c<='z';c++){
			m[c]=min(m[c],(int)count(all(s),c));	
		}
	}
	for(char c='a';c<='z';c++){
		for(int i=1;i<=m[c];i++){
			cout<<c;
		}
	}
}
