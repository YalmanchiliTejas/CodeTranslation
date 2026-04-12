#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int G[n][n] = {};
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = 1; G[b][a] = 1;
    }

    vector<int> A;
    for(int i = 1; i < n; i++){
        A.push_back(i);
    }
    
    int cnt = 0;
    do{
        int s = 0, e, p = 1;   //start, end, product
        for(int i = 0; i < A.size(); i++){
            e = A[i];
            p *= G[s][e];
            if(p){
                s = e;
            }
            else break;
        }
        if(p) cnt++;
    }while(next_permutation(A.begin(), A.end()));

    cout << cnt << endl;

    return 0;
}