#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair <int,ii>
#define iil pair<ll,ll>
#define iiil pair<ll,iil>
#define max3(a,b,c) max(a, max(b,c))
#define min3(a,b,c) min(a, min(b,c))
#define s(v) sort(v.begin(),v.end())
#define pf printf
#define sf scanf
#define MIN INT_MIN
#define MAX INT_MAX
#define accepted 0
#define GCD(x,y)  __gcd(x, y)
#define endl "\n"
using namespace std;
const int maxn = 1e5 + 69;
//int vis[maxn];
//int indegree[maxn];
//vector<int> graph[maxn];
//vector<int> order;
/**
int gx[]= {2,2,-2,-2,1,-1,1,-1};
int gy[] ={1,-1,1,-1,2,2,-2,-2};

void DFS(int a,bool tpsort){
        vis[a] = 1;
    for(int i=0;i<graph[a].size();i++){
        int r = graph[a][i];
            if(vis[r]==0){
                DFS(r,tpsort);
            }
    }
    if(tpsort)order.push_back(a);
}

int vis[maxn],l[maxn],l2[maxn];
vector<int> graph[maxn];
vector<int> cst[maxn];
int mx,ans;
void BFS(int root){
    memset(vis,0,sizeof(vis));
    memset(l,0,sizeof(l));
    vis[root] = 1;
    l[root] = 0;
    queue <int> q;
    ans = 0;
    mx = root;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int p = graph[cur].size();
        for(int i=0;i<p;i++){
            int r = graph[cur][i];
            if(vis[r]==0){
                vis[r] = 1 ;
                l[r] = l[cur] + cst[cur][i];
                if(l[r]>ans){
                    ans = l[r];
                    mx = r;
                }
                q.push(r);
            }
        }
    }
   // cout<< ans <<endl;
}
void ultapoth(int root){
    memset(vis,0,sizeof(vis));
    memset(l2,0,sizeof(l2));
    vis[root] = 1;
    l2[root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int p = graph[cur].size();
        for(int i=0;i<p;i++){
            int r = graph[cur][i];
            if(vis[r]==0){
                vis[r] = 1 ;
                l2[r] = l2[cur] + cst[cur][i];
                q.push(r);
            }
        }
    }
   // cout<< ans <<endl;
}
**/
int main(){
    //fast
    int n;  sf("%d",&n);
        if(n>=30)pf("Yes\n");
        else pf("No\n");

    return accepted;
}
