#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
//#define REP(i, n) for(int i = 0; i < n; i++)
//#define REPR(i, n) for(int i = n; i >= 0; i--)
//#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 1e9
//#define ALL(v) v.begin(), v.end()

using namespace std;
//typedef long long ll;

int main() { //int argc, const char * argv[]

    cin.tie(0);
    ios::sync_with_stdio(false);

    //std::cout << "Hello, World!\n";
    
    int A, B;
    string ans = "";
    cin>>A>>B;

    if (A==B) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }       
    
    return 0;
}
