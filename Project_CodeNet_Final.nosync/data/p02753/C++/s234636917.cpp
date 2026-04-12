#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

int cnt=0;
string S;

void solve(){
    rep(i,3){
        if(S[i]=='A'){
            cnt++;
        }
    }
    if(cnt==3 || cnt==0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main(){
    cin >> S;

    solve();
}
