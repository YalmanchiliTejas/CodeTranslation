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
    std::vector<std::string> a0;
    for(int i=0; i<H; ++i){
        std::string b; std::cin >> b; a0.push_back(b);
    }

    std::vector<std::string> a1;
    for(int i=0; i<a0.size(); ++i){
        bool flag=false;
        for(int j=0; j<a0.at(0).size(); ++j){
            if(a0[i][j]=='#'){
                flag=true;
                break;
            }
        }
        if(flag) a1.push_back(a0[i]);
    }

    std::vector<std::string> a2(a1.size());
    for(int i=0; i<a1.at(0).size(); ++i){
        bool flag=false;
        for(int j=0; j<a1.size(); ++j){
            if(a1[j][i]=='#'){
                flag=true;
                break;
            }
        }
        if(flag){
            for(int j=0; j<a1.size(); ++j){
                a2[j] += a1[j][i];
            }
        }
    }

    for(int i=0; i<a2.size(); ++i){
        std::cout << a2[i] << '\n';
    }
    return 0;
}
