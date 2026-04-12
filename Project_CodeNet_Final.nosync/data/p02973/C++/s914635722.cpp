#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using TP = tuple<ll, ll, ll>;
ll MOD = 1e9+7;
ll INF = 1e18;

int main() {
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> gr;
    ll a;
    vector<ll>::iterator itl;
    REP(i, n){
        cin >> a;
        itl = lower_bound(gr.begin(), gr.end(), a);
        //cout << ":"  << "," << itl -gr.begin() << endl;
        if( itl - gr.begin() <= 0 ){
            gr.insert(gr.begin(),a);
        }else{
            gr[distance(gr.begin(), itl)-1] = a;
        }
//        sort(gr.begin(), gr.end(), std::greater<ll>());
        //sort(gr.begin(), gr.end());
//        REP(j, gr.size()){
//            cout << gr[j] << " ";
//        }
//        cout << endl;
    }
    cout << gr.size() << endl;
    return 0;
}
