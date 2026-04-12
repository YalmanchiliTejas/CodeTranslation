#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(c) (c).begin(),(c).end()
int main(){
	while(true){
		int n,ans=1;
		cin >> n;
		if(!n) break;
		vector<int> a,ac(3);
		rep1(i,3) a.push_back(i);
		rep(i,n){
			string s;
			cin >> s;
			if(s[0]=='N'){
				ac[0]=a[1];
				ac[1]=7-a[0];
				ac[2]=a[2];
			}
			if(s[0]=='E'){
				ac[0]=7-a[2];
				ac[1]=a[1];
				ac[2]=a[0];
			}
			if(s[0]=='W'){
				ac[0]=a[2];
				ac[1]=a[1];
				ac[2]=7-a[0];
			}
			if(s[0]=='S'){
				ac[0]=7-a[1];
				ac[1]=a[0];
				ac[2]=a[2];
			}
			if(s[0]=='R'){
				ac[0]=a[0];
				ac[1]=a[2];
				ac[2]=7-a[1];
			}
			if(s[0]=='L'){
				ac[0]=a[0];
				ac[1]=7-a[2];
				ac[2]=a[1];
			}
			a=ac;
			ans+=a[0];
		}
		cout << ans << endl;
	}
	return 0;
}