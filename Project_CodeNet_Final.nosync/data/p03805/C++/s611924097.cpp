#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M,rs;
    rs = 0;
    vector<int> a,b;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int inA,inB;
        cin >> inA >> inB;
        a.emplace_back(inA);
        b.emplace_back(inB);
    }
    //頂点の配列
    vector<int> one_case;
    for (int i = 2; i <= N; i++) { // one_case = {2,3,...N} とする
        one_case.emplace_back(i);
    }
    int ca,cb;
    bool isFind;
    do {
        one_case.emplace_back(1);
        for (int i = 0; i < N-1; i++){
            isFind = false;
            ca = min(one_case.at(i),one_case.at(i+1));
            cb = max(one_case.at(i),one_case.at(i+1));
            for (int j = 0; j<M; j++) {
                if(a.at(j) == ca && b.at(j) == cb){
                    isFind = true;
                    break;
                }
            }
            if (isFind == false){
                break;
            }
            if(i == N-2){
                rs++;
            }
        }
        
        one_case.pop_back();
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ
    cout << rs << endl;
 
    return 0;
}
 
