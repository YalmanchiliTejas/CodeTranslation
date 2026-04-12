#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    //freopen("test.in", "r+", stdin);
    int N, H, res = 0, mx = -1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> H;
        if(H >= mx)res++;
        mx = max(mx, H);
    }
    cout << res << endl;
}
