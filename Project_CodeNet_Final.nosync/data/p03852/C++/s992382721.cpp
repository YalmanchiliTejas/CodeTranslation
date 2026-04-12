#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using namespace std;

string YorN(bool P) { if (P)return "Yes"; else return "No"; }

int main() {

    char c;
    cin >> c;
    
    cout << ((c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') ? "vowel" : "consonant") << endl;

    return 0;

}