#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string S;
    cin >> S;

    if((find(S.begin(), S.end(), 'A')!=S.end()) && (find(S.begin(), S.end(), 'B')!=S.end())){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}