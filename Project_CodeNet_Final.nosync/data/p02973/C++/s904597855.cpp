#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

ll N;
int tmp,val,maxc;
vi As;
vi colors;

void solve(){
    for(int i = N-1; i >=0; --i){
        val = As[i];
        if(i == N-1){
            colors.push_back(val);
            continue;
        }

        auto itr = upper_bound(colors.begin(), colors.end(), val);
        int id = itr - colors.begin();
        // cout << id << endl;
        if(id == colors.size()) colors.push_back(val);
        else{
            colors[id] = val;
        }
    }

    cout << colors.size() << endl;
}

int main(){
    cin >> N;
    As.resize(N);

    rep(i,N){
        cin >> As[i];
    }

    solve();
}
