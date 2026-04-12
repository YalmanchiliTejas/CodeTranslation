#include <bits/stdc++.h>
using namespace std;
int main(){
    int longs, number;
    cin >> longs;
    vector<char> one(longs);
    for(int i = 0; i < longs; i++){
        cin >> one.at(i);
    }
  cin >> number;
    for(int i = 0; i < longs; i++){
    if(one.at(i) != one.at(number - 1)) one.at(i) = '*';
    }
    for(int i = 0; i < longs; i++){
        cout << one.at(i);
        if(i == longs - 1) cout << endl;
    }
}