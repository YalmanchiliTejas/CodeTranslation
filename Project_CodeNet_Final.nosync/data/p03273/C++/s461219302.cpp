#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

char get_wb(int i){
    if(i == 0){
        return '.';
    }else
    {
        return '#';
    }
}

int a[110][110];
int h_white[110];
int w_white[110];


int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int H, W;
    cin >> H >> W;

    string tmp_s;
    for(int i = 0; i < H; i++){
        cin >> tmp_s;
        for(int j = 0; j < W; j++){
            if(tmp_s[j] == '.'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }


    int tmp_sum = 0;
    for(int i = 0; i < H; i++){
        tmp_sum = 0;
        for(int j = 0; j < W; j++){
            tmp_sum += a[i][j];
        }
        if(tmp_sum==0){
            h_white[i] = 1;
        }else{
            h_white[i] = 0;
        }
    }

    for(int j = 0; j < W; j++){
        tmp_sum = 0;
        for(int i = 0; i < H; i++){
            tmp_sum += a[i][j];
        }
        if(tmp_sum==0){
            w_white[j] = 1;
        }else{
            w_white[j] = 0;
        }
    }

    vector<string> ans;
    for(int i = 0; i < H; i++){
        tmp_s = "";
        for(int j = 0; j < W; j++){
            if(w_white[j] == 0){
                tmp_s.push_back(get_wb(a[i][j]));
            }
        }
        if(h_white[i] == 0){
            ans.push_back(tmp_s);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}
