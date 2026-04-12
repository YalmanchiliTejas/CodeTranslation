#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll a[27],b[27];

int main() {
	ll n;
	cin>>n;
	for(int i=0;i<27;i++){
		b[i]=INF;
	}
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			char z=s[j];
			a[z-'a']++;
		}
		for(int j=0;j<27;j++){
			b[j]=min(a[j],b[j]);
			a[j]=0;
		}
	}
	for(int i=0;i<27;i++){
		if(b[i]==0){
			continue;
		}
		for(int j=0;j<b[i];j++){
			cout << char(i+'a');
		}
	}
}