#include<bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
using namespace std;
const int N=1e4+5,M=1e9+7;
const ull base=13331;
const double Pi=acos(-1.0);
const ll C=299792458;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int pre=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k>=pre){
			ans++;
			pre=k;
		}
	}
	cout<<ans<<endl;
}