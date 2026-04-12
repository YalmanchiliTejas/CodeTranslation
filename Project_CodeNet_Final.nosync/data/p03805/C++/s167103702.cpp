#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using vc=vector<char>;

int dr[4]={-1,0,0,1};
int dc[4]={0,-1,1,0};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> graph(n,vi());
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi road(n);
    rep(i,n) road[i]=i;
    int ans=0;
    do{
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(find(graph[road[i]].begin(),graph[road[i]].end(),road[i+1])==graph[road[i]].end()) flag=false;
        }
        if(flag){
            //rep(i,n) cout << road[i] << " ";
            //cout << endl;
            ans++;
        }
    }while(next_permutation(road.begin()+1,road.end()));

    cout << ans << endl;
}