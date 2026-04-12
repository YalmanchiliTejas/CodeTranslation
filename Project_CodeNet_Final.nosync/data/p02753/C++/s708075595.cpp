#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    int count = 0;
    for(int i = 0; i < l-1; i++){
        if(s[i] != s[i+1]) count++;
    }
    if(count != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}