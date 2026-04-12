#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int s[110000];
bool flag[110000] = {};

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    long long int ans = 0;
    for(int i = 1; i < N; i++){
        long long int S = 0;
        vector<int> v;
        for(int j = 1; i * j < N - 1; j++){
            int pos1 = i * j;
            int pos2 = N - 1 - i * j;
            if(pos1 + i >= N){
                break;
            }
            if(flag[pos1] || flag[pos2] || pos1 == pos2){
                break;
            }
            flag[pos1] = true;
            flag[pos2] = true;
            v.push_back(pos1);
            v.push_back(pos2);
            S += s[pos1] + s[pos2];
            ans = max(ans, S);
            /*
            cout << i << " " << j << endl;
            cout << pos1 << " " << pos2 << endl;
            */
        }
        for(int num : v){
            flag[num] = false;
        }
    }
    cout << ans << endl;
    return 0;
}