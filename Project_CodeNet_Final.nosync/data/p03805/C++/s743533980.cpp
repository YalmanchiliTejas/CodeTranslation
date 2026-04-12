#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, M; cin >> N >> M;
    int a[N];
    vector<vector<int>> G(N);
    int v1,v2;
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2; v1--; v2--;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    int cnt = 0; bool check;
    do{
        for (int i = 0; i < N-1; i++) {
            check = false;
            for ( int v : G[a[i]] ){
                if(v == a[i+1]){
                    check = true;
                }
            }
            if(!check){
                break;
            }
        }
        if(check){
            cnt++;
        }


    } while(next_permutation(a + 1, a + N));

    printf("%d\n", cnt);
}
