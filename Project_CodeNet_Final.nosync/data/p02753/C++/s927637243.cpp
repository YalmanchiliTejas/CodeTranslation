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
    int a = 0;
    int b = 0;
    for(int i=0; i<3; i++){
        if(s[i]=='A'){
            a += 1;
        }else{
            b += 1;
        }
    }
    if(a*b==0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}