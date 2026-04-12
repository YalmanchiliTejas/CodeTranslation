#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <tuple>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main()
{
    int n,m;
    cin>>n>>m;
    bool g[10][10]={false};
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a][b]=g[b][a]=true;
    }

    vector<int> p;
    for(int i=0;i<n;i++)p.push_back(i);

    int cnt=0;

    do{
        if(p[0]!=0)continue;
        bool ok=true;
        for(int i=0;i<p.size()-1;i++){
            if(!g[p[i]][p[i+1]])ok=false;
        }
        if(ok)cnt++;
    }
    while(next_permutation(ALL(p)));
    
    cout << cnt <<endl;
    
    return 0;
}
