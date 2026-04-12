#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

int main(){
    int N;
    cin >> N;
    vector<int> s(N);
    for(int i = 0;i < N;i++)    cin >> s[i];
    LL ans = 0;
    for(int c = 1;c < N;c++){
        LL score = 0;
        for(int k = 0;;k++){
            int A = (N-1)-k*c;
            if(A <= 0 || A-c <= 0)    break;
            if(A%c == 0 && A <= k*c)    break;
            score += s[(N-1)-k*c];
            score += s[k*c];
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
}