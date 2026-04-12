#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<limits>
#include<queue>
#include<stack>
#include<math.h>
#include<array>
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
int main(){
    int X;
    cin >> X;
    if(X == 3 || X == 5 || X == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}