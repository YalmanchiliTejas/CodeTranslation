#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> a;

void mainmain(){
    for (int i = 0;i < 3; i++){
        int n;
        cin >> n;
        a.push_back(n);
    }

    string str = to_string(a[1]) + to_string(a[2]);
    int b = stoi(str);
    if (b%4==0){cout << "YES" << endl;}
    else{cout << "NO" << endl;}

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    mainmain();
    return 0;
}