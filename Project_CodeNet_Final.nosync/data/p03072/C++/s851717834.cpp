//https://atcoder.jp/contests/abc124/tasks/abc124_b
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for(auto &x : H){
        cin >> x;
    }
    vector<int> view(N);
    int tmp = H[0];
    for(int i = 0; i < (int)H.size(); i++){
        if(tmp <= H[i]){
            tmp = H[i];
            view[i] = 1;
        }
    }
    cout << count(ALL(view), 1) << endl;
    return 0;
}