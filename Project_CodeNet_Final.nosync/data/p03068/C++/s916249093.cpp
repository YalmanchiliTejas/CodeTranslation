#include<bits/stdc++.h>
#define hh ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100;
char s[maxn]={0};
int k,n;
int main() {
	hh;
	cin>>n;
	cin>>s;
	cin>>k;
	for(int i=0;i<n;i++){
		if(s[i]!=s[k-1]){
			s[i]='*';
		}
	}
	cout<<s<<endl;
	return 0;
}