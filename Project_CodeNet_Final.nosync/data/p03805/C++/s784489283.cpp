#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define SAMPLE 1000000
using namespace std;
using P=pair<int,int>;
using M=map<int,int>;
using ll=long long;
 
int main(){
    int n,m;cin>>n>>m;
    vector<set<int>> edge(n);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        edge[a-1].insert(b-1);
        edge[b-1].insert(a-1);
    }

    int cnt=0;

    vector<int> path(n-1);
    for(int i=0;i<n-1;i++) path[i]=i+1;
    sort(path.begin(),path.end());
    
    do{
        set<int> visited;
        int now=0;
        visited.insert(0);
        bool able=true;

        for(int i=0;i<n-1;i++){
            int next=path[i];
            if(edge[now].count(next)==1&&visited.count(next)==0){
                now=next;
                visited.insert(next);
            }
            else {
                able=false;
                break;
            }
        }

        if(able) cnt++;
    }while(next_permutation(path.begin(),path.end()));

    cout << cnt << endl;
    
}