#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    map<int,int> light;
    vector<int> d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
        light[--d[i]] = i;
    }
    int v[n][k];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    vector<int> dp(1<<m, 1<<30);
    dp[(1<<m)-1] = 0;
    queue<int> q;
    q.push((1<<m)-1);
    while(!q.empty()){
        int j = q.front();  q.pop();
        if(j == 0){
            cout << dp[j] << endl;
            return 0;
        }
        for(int col = 0; col < k; col++){
            int nbit = 0;
            for(int x = 0; x < m; x++){
                if((j>>x)&1){
                    if(light.count(v[d[x]][col])){
                        nbit |= 1<<light[v[d[x]][col]];
                    }
                }
            }
            if(dp[nbit] == 1<<30){
                dp[nbit] = dp[j]+1;
                q.push(nbit);
            }
        }
    }
}
