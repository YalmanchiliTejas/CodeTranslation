#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[50], b[50];
    int e[10][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            e[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        e[a[i]][b[i]]++;
        e[b[i]][a[i]]++;
    }
    int ans = 0;
    int seq[10];
    for(int i = 0; i < n; i++){
        seq[i] = i;
    }
    do{
        bool f = true;
        for(int i = 0; i < n - 1; i++){
            if(e[seq[i]][seq[i + 1]] == 0){
                f = false;
            }
        }
        if(f){
            ans++;
        }
    }
    while(next_permutation(seq + 1, seq + n));
    cout << ans << endl;
}