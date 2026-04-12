#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int main(){
    char ch;
    cin >> ch;
    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'u':
        case 'o':
            cout << "vowel" << endl;
            break;
        default:
            cout << "consonant" << endl;
            break;
    }
}