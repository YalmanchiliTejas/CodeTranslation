#include <bits/stdc++.h>
#define debug(...)
#include <complex.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H , W;
    cin >> H >> W;
    vector<string>grid(H);
    for(string & s : grid)
        cin >> s;
    bool maybe = true;
    const int inf = 10;
    auto Count = [&](int Row , int Col){
        int cnt0 = inf , cnt1 = inf;
        for(int i = Col + 1; i < W; i++){
            if(grid[Row][i] == '#'){
                cnt0 = i;break;
            }
        }
        for(int i = Row + 1; i < H; i++){
            if(grid[i][Col] == '#'){
                cnt1 = i;
                break;
            }
        }
        return make_pair(cnt0 , cnt1); /// right , down
    };

     auto BOUND = [&](int i , int j){ return i >= 0 && i < H && j >= 0 && j < W; };
     int D = 0 , R = 0;
     int cnt = 0;
     vector<vector<bool>> visited(H , vector<bool> (W , false));
     while(BOUND(D , R)){
        int a, b;
        tie(a , b) = Count(D , R);
        if(BOUND(D , R)){
            visited[D][R] = true;
        }
        if(a != b){
            if(a < b)R++;
            else D++;
        }
        else if(a== b && a != inf && a- 1 == R && b - 1 == D){
            maybe = false;
            break;
        }

        else if(a == b && a== inf){
            D++ , R++;
        }
        else{
            maybe = false;
            break;
        }
        cnt++;
        if(cnt >= H * W){
            maybe = false;
            break;
        }
     }
     for(int i = 0; i < H; ++i)for(int j = 0; j < W; j++)if(grid[i][j] == '#')maybe &= (visited[i][j] == true);
     cout << (maybe && BOUND(D - 1 , R - 1) ? "Possible" : "Impossible") << '\n';



    return 0;
}












