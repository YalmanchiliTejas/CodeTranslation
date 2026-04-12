#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, 0));
    for(int i =0; i<m; i++){
        cin >> a >> b;
        G[a-1][b-1] = 1;
        G[b-1][a-1] = 1;
    }
    vector<int> v(n);
    for(int i = 0 ; i<n; i++){
        v[i] = i;
    }
    int num = 0;
    do{
        for(int i=0; i<n-1; i++){
            if(G[v[i]][v[i+1]]==1){ 
                if(i == n-2) num++;
                continue;
            }else break;
        }
    }while(next_permutation(v.begin()+1, v.end()));

    cout << num << endl;
    return 0;
}