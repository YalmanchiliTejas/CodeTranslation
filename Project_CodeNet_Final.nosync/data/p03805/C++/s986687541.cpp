#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int> > list(N, vector<int>(N,0));
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b; a--; b--;
        list[a][b] = 1;
        list[b][a] = 1;
    }

    vector<int> v(N-1);
    for(int i=0;i<N-1;i++){
        v[i] = i+1;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    do{
        int pos = 0;
        for(int i=0;i<v.size();i++){
            if(list[pos][v[i]] == 0) break;
            pos = v[i];
            if(i == v.size()-1) ans++;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}