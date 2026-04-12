#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    int A[N]; rep(i, N) cin >> A[i];
    vector<int> vec;
    rep(i, N){
        if(i == 0) vec.push_back(A[i]);
        else{
            int ng = -1, ok = vec.size();
            int m = (ok+ng)/2;
            while(abs(ok-ng) > 1){
                if(A[i] > vec[m]) ok = m;
                else ng = m;
                m = (ok+ng)/2;
            }
            if(ok == vec.size()) vec.push_back(A[i]);
            else vec[ok] = A[i];
        }
    }
    //rep(i, vec.size()) cout << vec[i] << " "; cout << endl;
    cout << vec.size() << endl;
    return 0;
}