#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

vector<int> binary(int i, int n, int N){
    int x = 1;
    rep(j,N){
        x *= n;
    }
    vector<int> vec(N);
    rep(j,N){
        x /= n;
        vec[j] = i / x;
        i -= x * vec[j];
    }
    return vec;
}

int vector_finder(vector<int> vec, int number){
    int len = vec.size();
    int cnt = 0;
    rep(i,len){
        if (vec[i] == number) cnt++;
    }
    if (cnt >= 1) return 1;
    else return 0;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int> > route(M);
    rep(i,M){
        cin >> route[i].first >> route[i].second;
        route[i].first--;
        route[i].second--;
    }
    vector<vector<int> > connection(N, vector<int>(0));
    rep(i,M){
        connection[route[i].first].push_back(route[i].second);
        connection[route[i].second].push_back(route[i].first);
    }
    int num = 1;
    rep(i, N - 1){
        num *= (N - 1);
    }
    int ans = 0;
    rep(i,num){
        vector<int> road = binary(i, N - 1, N - 1);
        vector<int> count(N - 1, 0);
        bool double_count = false;
        bool possible = true;
        rep(j,N - 1){
            count[road[j]]++;
        }
        rep(j,N - 1){
            if (count[j] >= 2) double_count = true;
        }
        rep(j,N - 1){
            road[j]++;
        }
        if (double_count) continue;
        else{
            if (vector_finder(connection[0], road[0]) == 0){
                possible = false;
            }
            rep(j,N - 2){
                if (vector_finder(connection[road[j]], road[j + 1]) == 0){
                    possible = false;
                }
            }
            if (possible) ans++;
        }
    }
    cout << ans << endl;
}
