#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

int main(){
    deque<int>dQ;
    int N; cin >> N;
    int a[N];rep(i, N)cin >> a[i];
    rep(i, N){
        if(i % 2){
            dQ.push_front(a[i]);
        }else{
            dQ.push_back(a[i]);
        }
    }
    if(N % 2 == 0)
        for_each(dQ.begin(), dQ.end(), [](int x){
            cout << x << ' ';
        });
    else
        for_each(dQ.rbegin(), dQ.rend(), [](int x){
            cout << x << ' ';
        });
}
