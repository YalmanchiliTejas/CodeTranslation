#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e18;
ll mod=1e9+7;
#define pb push_back
#define se second
#define fi first
#define maxe max_element
#define mine min_element
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define boost  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<int> graph[205];
int color[205];
int nCk[100][100];
bool bipartite_jugding(int v, int c){
    color[v] = c;
    for(int i = 0; i < graph[v].size(); ++i){
        if(color[graph[v][i]] == c) return false;
        if(color[graph[v][i]] == 0 && !bipartite_jugding(graph[v][i], -c)){
            return false;
        }
    }
    return true;
}

 void combi() {
	for (int i = 0; i <= 99; ++i) nCk[i][0] = 1;
	for (int i = 1; i <= 99; ++i) for (int j = 1; j <= i; ++j) {
		nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1]) % mod;
	}
}

long long expo(ll x,ll n,ll M)
{

    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*expo((x*x)%M,(n-1)/2,M))%M;

}

void solve()
{
   int n,m;
   cin>>n>>m;
   if(n==m)
    cout<<"Yes"<<endl;
   else
    cout<<"No"<<endl;

}

int main(){
    boost;
  solve();
}
