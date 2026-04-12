#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> A;
    rep(i,N) A.emplace_back(i);
    bool V[8][8]={};
    int a,b;
    rep(i,M){
        cin >> a >> b;
        a--,b--;
        V[a][b] = true;
        V[b][a] = true;
    }
    int res = 0;
    do {
        bool flag = true;
        for(int i=1;i<N;i++){
            if(!V[A[i]][A[i-1]]){
                flag = false;
                break;
            } 
        }
        if(flag) res++; 
    } while (std::next_permutation(A.begin()+1, A.end()));
    cout << res << endl;
 
    return 0;
}