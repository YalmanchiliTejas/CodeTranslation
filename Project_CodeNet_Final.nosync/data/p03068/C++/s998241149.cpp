#include<bits/stdc++.h>
#define mov(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define INF 1e9+5
typedef long long ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != s[k-1]) s[i] = '*';
	}
	cout<<s<<"\n";
	
	
}