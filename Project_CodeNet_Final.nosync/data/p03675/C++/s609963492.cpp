#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <deque>
#include <cstdio>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

using namespace std;

int main(){
    deque<int> bs;
    int n;
    cin >> n;
    int r = (n - 1) % 2;
    rep(i, n){
        int a;
        cin >> a;
        if(i % 2 == r){
            bs.push_front(a);
        }else{
            bs.push_back(a);
        }
    }
    cout << bs[0];
    for(int i = 1; i < n; i++){
        cout << " " << bs[i];
    }
    cout << endl;

    return 0;
}
