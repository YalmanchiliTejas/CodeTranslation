#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] and s[1]==s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}