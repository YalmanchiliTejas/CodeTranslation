#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    ll n;
    int x, m;
    cin >> n>>x>>m;

    vector<int> order;
    order.push_back(x);
    vector<bool> seen(m, false);

    for(int i = 0; i < n-1; ++i){
        int next = ((ll)order.back()*order.back())%m;

        if(!seen[next]){
            seen[next] = true;
            order.push_back(next);
        }
        else{
            int s = order.size();
            int j = s-1;
            while(order[j] != next) --j;

            vector<int> front, loop;
            for(int k = 0; k < j; ++k){
                front.push_back(order[k]);
            }
            ll loopsum = 0;
            for(int k = j; k < s; ++k){
                loop.push_back(order[k]);
                loopsum += order[k];
            }

            // for(int j : front) cout << j << " ";
            // cout << "\n";

            // for(int j : loop) cout << j << " ";
            // cout << "\n";

            ll sum = 0;
            for(int j : front) sum += j;

            ll left = n-(int)front.size();

            sum += (left/(int)loop.size()) * loopsum;

            int mod = (int)(left%(int)loop.size());

            for(int j = 0; j < mod; ++j){
                sum += loop[j];
            }

            cout << sum << "\n";
            return;
        }
    }

    ll sum = 0;
    for(int i : order){
        sum += i;
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}