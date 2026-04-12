#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
using namespace std;

int main(){
	while(1){
		int m[5],a[5];
		cin>>m[0]>>a[0];
		if(m[0]==0&&a[0]==0) break;
		rep(i,1,5) cin>>m[i]>>a[i];
		pair<int,int> data[5];
		rep(i,0,5){
			data[i].first=m[i]+a[i];
			data[i].second=i;
		}
		sort(data,data+5);
		char c='A'+data[4].second;
		cout<<c<<" "<<data[4].first<<endl;
	}
}