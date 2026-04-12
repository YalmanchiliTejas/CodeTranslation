#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

vector<int> v(3009);

pair<int, int> memo[3009][3009][2];

pair<int, int> dp(int left, int right, int player){
    if(left > right){
        return {0,0}; //TO CHECK
    }
    if(memo[left][right][player] != make_pair((int)-1,(int)-1)) return memo[left][right][player];
    if(player){
        //MAX
        pair<int, int> p = {v[left],0};
        pair<int, int> p1 = {v[right],0};

        pair<int, int> t = dp(left+1, right, 0);
        pair<int, int> t1 = dp(left, right-1, 0);

        if(p.first+t.first-(p.second+t.second) > p1.first+t1.first-(p1.second+t1.second)){
            return memo[left][right][player] = {p.first+t.first,(p.second+t.second)};
        }else{
            return memo[left][right][player] ={p1.first+t1.first,(p1.second+t1.second)};
        }
    }else{
        pair<int, int> p = {0,v[left]};
        pair<int, int> p1 = {0,v[right]};

        pair<int, int> t = dp(left+1, right, 1);
        pair<int, int> t1 = dp(left, right-1, 1);

        if(p.first+t.first-(p.second+t.second) > p1.first+t1.first-(p1.second+t1.second)){
            return memo[left][right][player] ={p1.first+t1.first,(p1.second+t1.second)};
        }else{
            return memo[left][right][player] ={p.first+t.first,(p.second+t.second)};
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < 3009; i++){
        for(int j = 0; j < 3009; j++){
            for(int k = 0; k < 2; k++){
                memo[i][j][k] = {-1,-1};
            }
        }
    }
    pair<int, int> p= dp(1,n, 1);
    cout << p.first-p.second << endl;
}

