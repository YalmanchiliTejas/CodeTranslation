#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void){
    int n,m;
    cin>>n>>m;
    int path[10][10]={};
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        path[a][b]++;
        path[b][a]++;
    }
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(i);
    int ans=0;
    int i;
    do{
        if(v[0]!=0) break;
        for(i=0;i<n-1;i++){
            if(path[v[i]][v[i+1]]==0) break;
        }
        if(i==n-1) ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
}