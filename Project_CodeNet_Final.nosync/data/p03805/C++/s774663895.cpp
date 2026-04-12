#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;cin>>n>>m;
  	vector<vector<int>> g(n,vector<int>(n));
  	for(int i=0;i<m;i++){
    	int a,b;
      	cin>>a>>b;
      	a--;b--;
      	g[a][b]=g[b][a]=1;
    }
  	vector<int> perm(n);
  	iota(perm.begin(),perm.end(),0);
  	int ans=0;
  	do{
    	int ok=1;
      	for(int i=0;i<n-1;i++){
        	if(g[perm[i]][perm[i+1]]==false) ok=0;
        }
      ans+=ok;
    }while(next_permutation(perm.begin()+1,perm.end()));
  	cout<<ans<<endl;
}