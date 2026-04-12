#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool ok[10][10];
int  N, M;
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ok[a][b] = true;
        ok[b][a] = true;
    }
    vector<int> sq;
    for(int i = 1; i <= N; i++){
        sq.push_back(i);
    }
    int ans = 0;
    do{
        bool flag = true;
        for(int i = 1; i < N; i++){
            if(!ok[sq[i - 1]][sq[i]]) flag = false;
        }
        if(flag) ans++;
    }while(next_permutation(sq.begin() + 1, sq.end()));
    cout << ans << endl;
    return 0;
}
