#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, int64_t> mp;
    for(int i=0; i<N; i++){
        int A;
        cin >> A;
        int a = A;
        for(int i=1; i*i<=a; i++){
            if(a%i == 0){
                mp[i] += A;
                if(i < a/i) mp[a/i] += A;
            }
        }
    }
    int64_t ans = 0;
    for(auto& p : mp) if(p.first > 1) ans = max(ans, p.second);
    cout << ans << endl;
    return 0;
}

