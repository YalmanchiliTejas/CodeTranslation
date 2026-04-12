#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(int st,int par,vector<vector<int> >&adj,vector<int>&p,vector<int>&h,vector<int>&g,vector<int>&b){
    bool ans=true;
    int flag=0;
    int x,y;
    for(int j=0;j<adj[st].size();j++){
        if(adj[st][j]!=par){
        //cout<<adj[st][j]<<" "<<par<<" "<<st<<endl;
            flag=1;
            ans=ans&dfs(adj[st][j],st,adj,p,h,g,b);
            g[st]+=g[adj[st][j]];
            b[st]+=b[adj[st][j]];
            p[st]+=p[adj[st][j]];
        }
    }
    if(flag==0){
        if(abs(h[st])>p[st]){
        	//cout<<st<<endl;
        	return false;
		}
        else {
            g[st]=(p[st]+h[st])/2;
            b[st]=(p[st]-h[st])/2;
            //cout<<st<<" "<<p[st]<<" "<<h[st]<<" "<<g[st]<<" "<<b[st]<<endl;
            if(g[st]+b[st]==p[st])
            return true;
            else return false;
        }
    }
    else{
        int x=(p[st]+h[st])/2;
        int y=(p[st]-h[st])/2;
        //cout<<st<<" "<<p[st]<<" "<<h[st]<<" "<<g[st]<<" "<<b[st]<<" "<<ans<<endl;
        if(x<0||y<0||(x+y)!=p[st]||(x-y)!=h[st]||abs(h[st])>p[st]||x<g[st])return ans&false;
        else {
        	g[st]=x;
        	b[st]=y;
        	return ans&true;
		}
    }
}

int main()
{
    int x;cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
