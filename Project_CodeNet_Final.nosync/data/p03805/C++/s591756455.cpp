#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(2 * M), b(2 * M);
    rep(i, M) cin >> a.at(i) >> b[i];
    rep(i, M) a.at(i + M) = b.at(i);
    rep(i, M) b.at(i + M) = a.at(i);
    vector<int> order(N);
    rep(i, N) order[i] = i + 1;
    int ans = 0;
    do{//すべての周り方を調べて道がつながっているのか調べる。
        bool flag = true;
        rep(i, N - 1){
            auto itr = a.begin();
            while(1){
                itr = find(itr, a.end(), order[i]);
                if(itr == a.end()){
                    flag = false;
                    break;
                }
                int index = itr - a.begin();
                if(b[index] == order[i + 1]){
                    break;
                }
                itr++;
            }
        }
        if(flag == true && order[0] == 1){
            ans++;
        }
    }while(next_permutation(all(order)));
    cout << ans << endl;
}