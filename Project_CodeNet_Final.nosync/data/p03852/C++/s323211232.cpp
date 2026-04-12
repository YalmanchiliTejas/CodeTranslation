#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;


int main() {
    char l;
    cin >> l;
    if(l == 'a' || l == 'e' || l == 'o' || l == 'u' || l == 'i'){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant"<< endl;
    }
}