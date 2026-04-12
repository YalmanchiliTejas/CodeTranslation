#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    rep(i, 0, n) cin >> S.at(i);
    
    rep(i,0,n){
        sort(all(S.at(i)));
        S.at(i) += " ";
    }
    rep(i, 0, 26){
        priority_queue<int, vector<int>, greater<int>> q;
        char x = 'a' + i;
        rep(j,0,n){
            int count = 0;
            while(S.at(j).at(0) == x){
                S.at(j) = S.at(j).substr(1);
                count++;
            }
            q.push(count);
        }
        int z = q.top();
        rep(i, 0, z){
            cout << x;
        }
    }
    cout << endl;
}