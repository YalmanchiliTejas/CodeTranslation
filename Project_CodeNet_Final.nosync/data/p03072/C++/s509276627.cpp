#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

ll N, th, cnt=0;
vll H;

void solve(){
    th = H[0];

    rep(i,N){
        if(H[i] >= th){
            th = H[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    cin >> N;
    H.resize(N,0);

    rep(i,N)
        cin >> H[i];

    solve();
}
