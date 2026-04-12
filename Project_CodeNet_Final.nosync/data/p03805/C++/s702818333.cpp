#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    bool edge[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            edge[i][j] = false;
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        edge[a-1][b-1] = true;
        edge[b-1][a-1] = true;
    }
    int perm[n];
    for(int i=0; i<n; i++){
        perm[i] = i;
    }
    int cnt = 0;
    do{
        if(perm[0]!=0) break;
        bool flag = true;
        for(int i=0; i<n-1; i++){
            if(!edge[perm[i]][perm[i+1]]){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }while(next_permutation(perm, perm+n));
    cout << cnt << endl;
    return 0;
}
