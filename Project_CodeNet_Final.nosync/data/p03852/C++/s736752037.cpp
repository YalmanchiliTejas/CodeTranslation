#include <bits/stdc++.h>
using namespace std;

int main(){
    char x;
    cin >> x;
    vector<char> v{'a', 'i', 'u', 'e', 'o'};
    auto itr = find(v.begin(), v.end(), x);
    if(itr != v.end()){cout << "vowel";}else{cout << "consonant";}
}