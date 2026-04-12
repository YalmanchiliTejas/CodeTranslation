#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i=1;i<N;++i){
        v.emplace_back(i);
    }
    vector<vector<int>> e(N, vector<int>());

    int a,b;
    for(int m=0;m<M;++m){
        cin >> a >> b;
        e[a-1].emplace_back(b-1);
        e[b-1].emplace_back(a-1);
    }

    int ans(0);
    bool f;
    do{
        f = true;
        if( find( e[0].begin(), e[0].end(), v[0] ) == e[0].end()) f = false;
        if(f){
            for(int i=0;i<N-2;++i){
                if( find( e[v[i]].begin(), e[v[i]].end(), v[i+1] ) == e[v[i]].end()) {
                    f = false;
                    break;
                }
            }
        }
        if(f) ++ans;
        
    }while( next_permutation( v.begin(), v.end()  ));
    
    cout << ans << endl;
    return 0;
}
