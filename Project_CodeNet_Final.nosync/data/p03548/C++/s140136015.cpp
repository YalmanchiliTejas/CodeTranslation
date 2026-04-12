#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x,y,z; cin>>x>>y>>z;
	vector<int> v(x);
	int i=0;
	while(i<x){
		for(int j=i; j<i+z; j++){
			v[j]=0;
		}
		i+=z;
		if(i+y+z>x) break;
		for(int k=i; k<i+y; k++){
			v[k]=1;
		}
		i+=y;
	}
	int ans=accumulate(v.begin(),v.end(),0);
	cout<<ans/y<<endl;
}