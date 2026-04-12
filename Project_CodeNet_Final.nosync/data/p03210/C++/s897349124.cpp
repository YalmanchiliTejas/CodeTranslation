#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d;
    cin >> d;
    if(d%2==1 && d!=1 && d!=9){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;


    return 0;
}