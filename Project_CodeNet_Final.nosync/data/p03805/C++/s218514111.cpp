#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {
    
    int N,M;
    cin >> N >> M;
    int a[M];
    int b[M];

    rep(i,M){
        cin >> a[i] >> b[i];
    }

    int ans = 0;

    vector<int> one_case;
    for (int i = 1; i <= N; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    do {
        int ok_1 = 1;
        for (int i = 0; i < N-1; i++){
            if(one_case[0]!=1){
                ok_1 = 0;
                break;
            }
            int ok_2 = 0;
            for (int j = 0; j < M; j++){
                if((one_case[i]==a[j])&(one_case[i+1]==b[j])){
                    ok_2 = 1;
                    break;
                }
                if((one_case[i]==b[j])&(one_case[i+1]==a[j])){
                    ok_2 = 1;
                    break;
                }
            }

            if(ok_2 != 1){
                ok_1 = 0;
                break;
            }
        }

        if(ok_1==1){
            ans++;
        }


    } while (next_permutation(one_case.begin(), one_case.end()));

    cout << ans << endl;

}