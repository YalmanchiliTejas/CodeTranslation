#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <math.h>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> H(N);

    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    int ans;
    ans = 0;
    for(int i_hotel = 0; i_hotel < N; i_hotel++){
        bool exist_higher_hotel = false;
        for(int j_hotel = 0; j_hotel < i_hotel; j_hotel++){
            if(H[i_hotel] < H[j_hotel]){
                exist_higher_hotel = true;
            }
        }
        if(!exist_higher_hotel){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
