#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;
ll memo[101][2][4]; //桁、未満、0以外の数
void init(){
    for (int yi = 0; yi < 101; ++yi) {
        for (int xi = 0; xi < 2; ++xi) {
            for (int zi = 0; zi < 4; ++zi) {
                memo[yi][xi][zi] = 0;
            }
        }
    }
}
vector<int> genDigit(string x){
    vector<int> result = vector<int>(101);
    for (int i = 0; i < 101; ++i) {
        result[i] = 0;
    }
    for(int i = 0; i < x.size(); i++){
        result[i] = x[x.size() - i - 1] -'0';
    }
    return result;
}

int main() {
    string N;
    cin >> N;
    ll K;
    cin >> K;
    init();
    auto dig = genDigit(N);
    memo[0][0][0] = 1;
    for(int i = 1; i < 101; i++){
        if(dig[101 - i - 1] == 0){
            for (int j = 0; j < 4; ++j) {
                memo[i][0][j] = memo[i-1][0][j];
                if(memo[i][0][0] != 0){
                    //continue;
                }
                if(j == 0){
                    memo[i][1][j] = memo[i-1][1][j];
                }else{
                    memo[i][1][j] = memo[i-1][1][j] + memo[i-1][1][j - 1] * 9;
                }
            }
        }else{
            for (int j = 0; j < 4; ++j) {
                if(j == 0){
                    memo[i][0][0] = 0;
                }else{
                    memo[i][0][j] = memo[i-1][0][j - 1];
                }
                if(j == 0){
                    memo[i][1][j] = memo[i-1][1][j] + memo[i-1][0][j];
                }else{
                    memo[i][1][j] = memo[i-1][1][j] + memo[i-1][0][j] + memo[i-1][1][j - 1] * (9) + memo[i-1][0][j-1] * (dig[101 - i - 1] - 1);
                }
            }
        }
    }
    cout << memo[100][0][K] + memo[100][1][K] << endl;


}
