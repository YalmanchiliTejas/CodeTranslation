#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <unordered_map>

#define BIG 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0;
    int a = 0;
    for(int i = 0;i < n;++i){
        int h;
        cin >> h;
        if(h >= max){
            ++a;
            max = h;
        }
    }
    cout << a << endl;
}
