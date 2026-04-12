using namespace std;
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}
