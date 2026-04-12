#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define N (1000000000+7)
#define INF (ll)1e16
typedef pair<int,int> P;
typedef long long ll;

struct edge{
    int to;
};

vector<edge>graph[10];

int main(void){
    int n,m,a,b;
    cin>>n>>m;
    vector<int>index(n);
    for(int i=0;i<n;i++)index[i]=i+1;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back({b});
        graph[b].push_back({a});
    }
    int ans=0,i=0;
    do{
        i=0;
        if(index[0]!=1)break;
        while(i<n-1){
            bool flag1=false;
            int now=index[i];
            for(int j=0;j<(int)graph[now].size();++j){
                if(graph[now][j].to==index[i+1]){
                    flag1=true;
                    break;
                }
            }
            if(!flag1)break;
            i++;
        }
        if(i==n-1)ans++;
    }while(next_permutation(index.begin(),index.end()));
    cout<<ans<<endl;
    return 0;
}