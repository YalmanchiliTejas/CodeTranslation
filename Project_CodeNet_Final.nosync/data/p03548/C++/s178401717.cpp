#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7,INF=1e17;
const int iINF=1e9;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int ans=0;
	x-=z;
	while(x>0){
		if(x>=y+z){
			x-=y+z;
			ans++;	
		}
		else break;
	}
	cout<<ans<<endl;
}
