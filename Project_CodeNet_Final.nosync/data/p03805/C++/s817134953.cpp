#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<vector<int>> v(n+1,vector<int>(n+1,0));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a][b]=v[b][a]=1;
	}
	vector<int> p(n-1);
	iota(p.begin(),p.end(),2);
	int ans=0;
	do{
		int ex=1;
		int flag=1;
		for(int i=1;i<n;i++){
			if(v[ex][p[i-1]]==0){
				flag=0;
				break;
			}
			ex=p[i-1];
		}
		if(flag)ans++;
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans<<endl;
	return 0;
}
