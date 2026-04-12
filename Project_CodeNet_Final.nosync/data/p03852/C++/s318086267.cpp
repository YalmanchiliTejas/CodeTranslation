#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
using namespace std;

typedef long long int ll;
typedef long double ld;



int main(){
    string a;
    cin >> a;
    if (a=="a" || a=="i" || a=="u" || a=="e" || a=="o"){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}