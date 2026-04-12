#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;
#define int long long


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h,w; cin >> h >> w;
    vector<string> a(h);
    for(int i = 0;i < h;i ++){
        cin >> a.at(i);
    }

    for(int i = 0;i < a.size();i ++){
        int sum = 0;
        for(int j = 0;j < w;j ++){
            sum += a.at(i).at(j);
        }

        if(sum == '.' * w){
            a.erase(a.begin() + i);
            i --;
        }
    }

    for(int i = 0;i < a.at(0).size();i ++){

        bool hantei = true;
        for(int j = 0;j < a.size();j ++){
            if(a.at(j).at(i) == '#') hantei = false;            
        }

        if(hantei == true){
            for(int j = 0;j < a.size();j ++){
                a.at(j).erase(a.at(j).begin() + i);
            }
            i --;
        }
    }

    for(int i = 0;i < a.size();i ++){
        for(int j = 0;j < a.at(0).size();j ++){
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}

