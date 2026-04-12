#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string first, second, third;
    first = s.at(0);
    second = s.at(1);
    third = s.at(2);
    if(first == second && second == third){
        cout << "No";
    } else {
        cout << "Yes";
    }
}