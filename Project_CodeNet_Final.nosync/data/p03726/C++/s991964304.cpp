#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define preturn(X) cout<<X<<endl; return 0
typedef long long ll;

int n;
vector<int> edges[100000+1];
int degree[100000+1];
bool visited[100000+1];
queue<int> q;

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    int x,y;
    rep(i,0,n-1){
    	cin>>x>>y;
    	edges[x].pb(y);
    	edges[y].pb(x);
    	degree[x]++;
    	degree[y]++;
    }
    rep(i,1,n+1){
    	if(degree[i]==1){
    		q.push(i);
    	}
    }
    while(!q.empty()){
    	int x = q.front();
    	visited[x] = 1;
    	q.pop();
    	iter(it,edges[x]){
    		if(!visited[(*it)]){
    			visited[(*it)] =1;
    			iter(it1,edges[(*it)]){
	    			if(!visited[(*it1)]){
	    				degree[(*it1)]--;
	    				if(degree[(*it1)]==0){
	    					preturn("First");
	    				}
	    				else if(degree[(*it1)]==1){
	    					q.push((*it1));
	    				}
	    			}	
    			}
    			break;
    		}
    	}
    }
    preturn("Second");
}