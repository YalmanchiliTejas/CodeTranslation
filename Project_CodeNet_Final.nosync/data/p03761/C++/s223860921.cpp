#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++){
        cin >> s[i];
    }

    map<char,int> cnt1,cnt2;
    for (char i = 'a'; i <= 'z'; i++){
        cnt1[i] = 0;
    }

    for (int i = 0; i < (int)s[0].size(); i++){
        cnt1[s[0][i]]++;
    }
    for (int i = 1; i < N; i++){
        for (char i = 'a'; i <= 'z'; i++){
            cnt2[i] = 0;
        }
        for (int k = 0; k < (int)s[i].size(); k++){
            cnt2[s[i][k]]++;
        }
        for (char k = 'a'; k <= 'z'; k++){
            if (cnt1[k] > cnt2[k]){
                cnt1[k] = cnt2[k];
            }
        }
    }
    for (char i = 'a'; i <= 'z'; i++){
        while(cnt1[i] != 0){
            cout << i;
            --cnt1[i];
        }
    }
    cout << endl;






    return 0;
}
