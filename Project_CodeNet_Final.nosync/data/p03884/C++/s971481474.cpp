#include <bits/stdc++.h>
using namespace std;

const int B = 500;


int main(){
    int64_t K;
    cin >> K;

    const int M = 600;

    int64_t C[M+1][8];
    C[0][0] = 1;
    for(int i=1; i<=M; i++) for(int j=0; j<=7; j++){
        C[i][j] = C[i-1][j];
        if(j) C[i][j] += C[i-1][j-1];
    }
    bool start = false;
    vector<int64_t> num;
    for(int i=M; i>=7; i--){
        int64_t q = K / C[i][7];
        if(start || q){
            start = true;
            K -= C[i][7] * q;
            num.push_back(q);
        }
    }
    reverse(num.begin(), num.end());
    string ans;
    cerr << num.size() << endl;
    for(int a : num){
        ans.append("FESTIVA");
        while(a--) ans.push_back('L');
    }
    cout << ans << endl;
    cerr << ans.size() << endl;
    return 0;
}
