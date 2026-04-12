#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 2; i <= n; i++){
        v.push_back(i);
    }
    int field[10][10];
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            field[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int in1, in2;
        cin >> in1 >> in2;
        field[in1][in2] = 1;
        field[in2][in1] = 1;
    }
    int ans = 0;
    do{
        bool flag = true;
        if(field[1][v[0]] == 0){
            continue;
        }
        for(int i = 0; i <= n - 3; i++){
            if(field[v[i]][v[i + 1]] == 0){
                flag = false;
            }
        }
        if(flag == true){
            ans++;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
        return 0;
}