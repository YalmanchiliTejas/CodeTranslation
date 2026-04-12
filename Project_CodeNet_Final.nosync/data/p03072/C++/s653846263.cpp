//  main.cpp
//  CppTest

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    /////////////////////
    // Write code below /
    /////////////////////
    int N;
    cin >> N;
    vector<int>H(N);
    for ( int i = 0; i < N; i++ ) cin >> H.at(i);
    
    int hotelCount = 0;
    for ( int i = 0; i < N; i++) {
        bool canSeeOcean = true;
        for ( int compared_i = 0; compared_i < i; compared_i++ ) {
            if ( H.at(i) < H.at(compared_i) ) {
                canSeeOcean = false;
                break;
            }
        }
        if (canSeeOcean) {
            hotelCount++;
        }
    }
    
    cout << hotelCount << endl;
    
    return 0;
}
