#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

void print_ans(bool flag){
    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }   
}

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    print_ans((r*100+10*g+b) % 4 == 0);
    return 0;
}
