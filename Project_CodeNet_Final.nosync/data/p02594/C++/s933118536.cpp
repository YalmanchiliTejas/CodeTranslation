#include <iostream> 
#include <sstream> // istringstream
#include <string> // 文字列
#include <algorithm> // アルゴリズム
#include <cmath> // 
#include <vector> // vector
#include <set> // set
#include <map> // map

using namespace std;

int main()
{   
    // input sample
    int N; 
    cin >> N;
    // int A[N];
    // for (int i = 0; i < N; ++i) cin >> A[i]; 
    // string s = "";

    // output sample
    if (N >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}