/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Jan 02 19:31:25 2019
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10];
int n;
int solve(int st){
    queue<pair<int,set<int> > >q;
    set<int>s={st};
    q.push(make_pair(st,s));
    int ans=0;
    while(!q.empty()){
    	 set<int>cur=q.front().second;

    	 int u=q.front().first;
    	 q.pop();
    	 if(cur.size()==n){
    	      ans++;
    	      continue;
    	 }
    	 for(int v:adj[u]){
    	 	if(cur.count(v)==0){
    	 		set<int>cc=cur;
    	 		cc.insert(v);
    	 		q.push(make_pair(v,cc));

    	 	}
    	 }
    }
    return ans;

	
}
int main(){
#ifndef ONLINE_JUDGE
   //freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
	int m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     adj[a].push_back(b);
     adj[b].push_back(a);
   }
   cout<<solve(1)<<endl;



}