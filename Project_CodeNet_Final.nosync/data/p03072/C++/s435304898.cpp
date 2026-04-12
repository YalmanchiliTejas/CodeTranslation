#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <numeric>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair <int,int> P;

int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i = 0;i<N;i++){
        cin >> H[i];
    }

    int MAX = 0;
    int cnt = 0;
    for(int i = 0;i<N;i++){
        if(H[i] >= MAX){
            cnt = cnt + 1;
            MAX = H[i];
        }
    }

    cout << cnt << endl;
}