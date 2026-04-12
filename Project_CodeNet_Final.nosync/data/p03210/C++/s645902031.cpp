#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int MAX = 999999999;

int main(){
    int n;
    cin >> n;

    if(n == 3 || n == 5 || n == 7){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}