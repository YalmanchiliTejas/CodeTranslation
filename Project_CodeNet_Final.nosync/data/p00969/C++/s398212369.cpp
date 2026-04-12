#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
・公差の候補はO(n^2)
・v0 v2 v4... vm
・v2 v4...は見なくていい
 */

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    vector<vector<int>> use(N,vector<int>(N,0));
    map<int,int> m;
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++) m[v[i]] = i;    
    int ans = 0;
    for(int i=0;i<N-1;i++) for(int j=i+1;j<N;j++){
        if(use[i][j]) continue;
        int d = v[j]-v[i];
        use[i][j] = 1;
        int len = 2,id = j;
        while(m.count(v[id]+d)){
            len++;
            use[id][m[v[id]+d]] = 1;
            id = m[v[id]+d];
        }
        ans = max(ans,len);
    }
    cout << ans << endl;
}
