#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(i, s, e) for(i = s; i < e; ++i)
#define FOR_INV(i, s, e) for(i = e - 1; i >= s; --i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;

LONG i, j, k;


LONG count(string N, int start_pos, int K){
    int keta = N.size() - start_pos;

    if(K == 1){
        if(keta == 0){
            return 0;
        }
        return 9 * (keta - 1) + (N[start_pos] - '0');
    }
    else if(K == 2){
        if(keta < 2){
            return 0;
        }
        else{
            // top 以外
            LONG sum = 9 * 9 *((keta - 2) * (keta - 1)) / 2;
            sum += (N[start_pos] - '0' - 1) * 9 * (keta - 1);

            ++start_pos;
            while(start_pos < N.size() && N[start_pos] == '0'){
                ++start_pos;
            }

            sum += count(N, start_pos, 1);
            return sum;
        }
    }
    else{
        if(keta < 3){
            return 0;
        }
        else{
            LONG sum = 9 * 9 * 9 * ((keta - 1) * (keta - 2) * (keta - 3)) / 6;
            sum += (N[start_pos] - '0' - 1) * 9 * 9 * ((keta - 2) * (keta - 1)) / 2;

            ++start_pos;
            while(start_pos < N.size() && N[start_pos] == '0'){
                ++start_pos;
            }

            sum += count(N, start_pos, 2);
            return sum;
        }
    }
}


int main(){
    string N;
    LONG K;
    cin >> N >> K;

    cout << count(N, 0, K);

}

