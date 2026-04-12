#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using Pos = std::pair<int, int>;
//cout<<fixed<<std:cout<<fixed<<setprecision(2)<<Max<<endl;
constexpr int mod = 1e9 + 7;

int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<bool>> Edge(N,vector<bool>(N,false));
    while(M--){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        Edge[a][b]=true;
        Edge[b][a]=true;
    }

    vector<int> p(N);
    for(int i=0;i<N;++i)
        p[i]=i;

    int ans=0;
    do{
        if(p[0]==0){
            for(int i=0;i<N-1;++i){
                if(!Edge[p[i]][p[i+1]])break;
                if(i==N-2)++ans;
            }
        }
    }while(std::next_permutation(begin(p),end(p)));

    cout<<ans<<endl;

    return 0;
}