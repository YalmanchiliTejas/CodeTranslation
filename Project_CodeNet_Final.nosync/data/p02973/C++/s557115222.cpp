#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N; cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];

    vector<int> ans; //A[i]がansの中で最小値以下 -> push_back(A[i])
                     //それ以外 -> ans未満のうち最大の色をにぶたん -> A[i]で書き換え
                     //ansは降順に並ぶ
    rep(i, N){
        if(i == 0) ans.push_back(A[i]);
        else{
            if(A[i] <= ans[ans.size()-1]) ans.push_back(A[i]);
            else{
                int val = A[i];
                if(val > ans[0]) ans[0] = val;
                else{
                    int ok = ans.size()-1, ng = 0;
                    int m = (ok+ng)/2;
                    //valより小さい最大の場所は? ans[ok+1] >= val > ans[ok]
                    while(abs(ok-ng) > 1){
                        if(val <= ans[m]){ //mは条件を満たさない
                            ng = m;
                        }
                        else ok = m;
                        m = (ok+ng)/2;
                    }
                    ans[ok] = val;
                }
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}

void solve(){}