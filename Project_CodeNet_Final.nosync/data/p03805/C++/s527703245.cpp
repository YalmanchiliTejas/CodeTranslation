#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<numeric>

#define _GLIBCXX_DEBUG
#define chinko long long

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> p(n);
	for(int i=0;i<n;i++) p[i]=i;
	
	int ans=0;
	
	bool visited[8][8]={};	
	
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		a--; b--;
		visited[a][b]=visited[b][a]=true;
	}
	
	do{
		bool anko=true;
		for(int i=0;i<n-1;++i){
			if(visited[p[i]][p[i+1]]) continue; 
			anko=false; 
			break;
		}
		if(anko) ++ans;
	}while(next_permutation(p.begin()+1,p.end()));
	
	cout<<ans<<endl;
	return 0;
}