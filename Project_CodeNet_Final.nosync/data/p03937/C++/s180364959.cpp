#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

int move(ll i, ll j,ll i_, ll j_,ll H,ll W, vector<vector<char>>& A){
    // cout << i << " " << j << " " << A[i][j] << endl;
    ll r=0;
    if(i_>0){ //down
        i+=i_;
        if(A[i][j-1]=='#') return 1;
    }else{  //right
        j+=j_;
        if(A[i-1][j]=='#') return 1;
    }
    // cout <<"move" <<  i << " " << j << " " << A[i][j] << endl;
    if(A[i][j]=='.') return 0;
    if(i==H && j==W) return 0;
    if(i==H){ //right
        return move(i, j, 0, 1, H, W, A);
    }else if(j==W){ //down
        return move(i, j, 1, 0, H ,W, A);
    }else{
        // cout << "DR" << endl;
        return max(move(i, j, 0, 1, H, W, A), move(i, j, 1, 0, H, W, A));
    }
}

int main(){
    ll H,W;
    cin>>H>>W;
    vector<vector<char>> A;

    vector<char> t;
    rep(j,W+2) t.push_back('.');
    A.push_back(t);

    rep(i,H){
        t.clear();
        t.push_back('.');
        char a;
        rep(j,W){
            cin >> a;
            t.push_back(a);
        }
        t.push_back('.');
        A.push_back(t);
    }
    t.clear();
    rep(j,W+2) t.push_back('.');
    ll r = max(move(1, 1, 0, 1, H, W, A), move(1, 1, 1, 0, H, W, A));

    if(r>0) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
    return 0;
}