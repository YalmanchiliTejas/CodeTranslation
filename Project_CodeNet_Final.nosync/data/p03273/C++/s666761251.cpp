#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll H, W; std::cin >> H >> W;
    std::vector<std::string> a;
    for(int i=0; i<H; ++i){
        std::string b; std::cin >> b; a.push_back(b);
    }

    std::vector<bool> row(H,false);
    std::vector<bool> col(W,false);
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            if(a[i][j]=='#'){
                row[i]=true;
                col[j]=true;
            }
        }
    }

    for(int i=0; i<H; ++i){
        if(row[i]){
            for(int j=0; j<W; ++j){
                if(col[j]){
                    std::cout << a[i][j];
                }
            }
            std::cout << '\n';
        }
    }

    return 0;
}
