#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	string s;
	char r[11]={'h','i','j','k','l','m','n','o','p','u','y'};
	while(cin>>s and s!="#"){
		int m=s.size();
		int a[m]={};
		rep(i,m){
			rep(j,11){
				if(s[i]==r[j]) a[i]=1;
			}
		}
		int ans=0;
		rep(i,m-1){
			if(a[i]!=a[i+1]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

