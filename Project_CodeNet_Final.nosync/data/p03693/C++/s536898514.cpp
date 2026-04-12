#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2);

    int num = vec.at(0) * 100 + vec.at(1) * 10 + vec.at(2);
    if(num % 4 == 0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}