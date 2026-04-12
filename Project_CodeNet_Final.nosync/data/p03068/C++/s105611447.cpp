#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 2e5 +11;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	string s;
	cin>>n>>s>>m;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[m-1])s[i]='*';
	}	
	cout<<s;
	return 0;
}