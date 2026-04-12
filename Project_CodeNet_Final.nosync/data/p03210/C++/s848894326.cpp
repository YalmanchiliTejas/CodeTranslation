
#include <iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N==3||N==5||N==7){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
