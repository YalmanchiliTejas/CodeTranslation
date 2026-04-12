#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll ans;
ll n,m;
ll a[105],b[105];
ll p[10];
bool e[10][10];
int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		e[a[i]][b[i]]=true;
		e[b[i]][a[i]]=true;
	}
	for(int i=0;i<n;i++){
		p[i]=i+1;
	}
	do{
		bool t=true;
		for(int i=0;i<n-1;i++){
			if(e[p[i]][p[i+1]]==false){
				t=false;
			}
		}
		if(t&&p[0]==1) ans++;
	} while(next_permutation(p,p+n));
	cout<<ans<<endl;
	
}
