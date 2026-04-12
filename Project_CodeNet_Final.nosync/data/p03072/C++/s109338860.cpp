#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>h(n);
    for(auto &x : h){
        cin >> x;
    }
    auto c = 0;
    for(int i = 0; i < n; ++i){
        auto flg = 1;
        for(int j = 0; j < i; ++j){
            if(h[j] > h[i]){
                flg = 0;
            }
        }
        if(flg){
            c++;
        }
    }
    cout << c;
    return 0;
}