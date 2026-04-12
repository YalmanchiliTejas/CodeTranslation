#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
int main(void)
{
    string s;
    int i, judge=0;
 
    cin >> s;
 
    for(i=0; i<s.size()-1; i++){
        if(s[i]=='A' && s[i+1]=='C'){
            judge=1;
            break;
        }
    }
 
    if(judge == 1){
        cout << "Yes" << endl;
    }
 
    else{
        cout << "No" << endl;
    }
 
    return 0;
}