#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e9 
typedef long long ll;
typedef long double ld;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    int a,b;
    REP(i,m){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> nodes(n-1);
    REP(i,n-1)nodes[i]=i+2;
    int cnt=0;
    if(SIZE(nodes)==1){
        cnt=1;
    }else{
        do{
            bool can=true;
            int from=1;
            REP(i,n-1){
                int to=nodes[i];
                if(find(ALL(edges[from]),to)!=edges[from].end()){
                    from=to;
                }else{
                    can=false;
                    break;
                }
            }
            if(can)cnt++;
        }while(next_permutation(ALL(nodes)));
    }
    cout<<cnt<<endl;
    return 0;
}
