#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<array>
#include<cstdio>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<cstring>
#include <climits>
#include <fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include <unordered_map>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    int sum = 0;
    for( int i = 1, cur = 1; i <= n; i++, cur++ ){
        sum += 800;
        if( cur == 15 ){
            sum -= 200;
            cur = 0;
        }
    }
    cout << sum << "\n";
}