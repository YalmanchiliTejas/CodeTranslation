#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int N;
        cin >> N;
        if(N==0)
            break;
        int s[111];
        for (int i = 0; i < N; i++)
            cin >> s[i];
        int M=-1, m=1111, sum = 0; // M:最大値, m:最小値
        for (int i = 0; i < N;i++){
            M = max(M, s[i]);
            m = min(m, s[i]);
            sum += s[i];
        }
        int ans = (sum - M - m) / (N - 2);
        cout << ans << endl;
    }
}
