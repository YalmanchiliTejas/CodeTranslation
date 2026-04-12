#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){
    
    string S;
    cin >> S;

    if(S == "AAA" || S == "BBB"){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}