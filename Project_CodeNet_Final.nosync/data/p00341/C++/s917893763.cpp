#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

signed main(){
    vector<int> q(12);
    for(int i = 0;i < 12;i++){
        cin >> q[i];
    }
    sort(q.begin(), q.end());
    bool f = true;
    for(int i = 0;i < 12;i+=4){
        if(q[i] == q[i+1] && q[i+1] == q[i+2] && q[i+2] == q[i+3]){

        }else{
            f = false;
        }
    }
    cout<<(f ? "yes" : "no")<<endl;
}

