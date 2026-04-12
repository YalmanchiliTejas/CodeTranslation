#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main(void) {
    string S;
    string a = "AAA";
    string b = "BBB";
    cin >> S;
    if(S == a || S == b){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}