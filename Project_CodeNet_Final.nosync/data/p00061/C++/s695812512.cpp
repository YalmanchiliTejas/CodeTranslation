#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define loop(i,a,b) for(int i=a; i<(int)(b); i++)
#define rep(i,n) loop(i,0,n)
#define all(c) (c).begin(), (c).end()

struct team {
    int id, score, rank;
};

int main(){
    int t, n;
    char c;
    vector<team> ts;
    while (cin >> t >> c >> n, t + n){
        ts.push_back({ t, n, 0 });
    }
    sort(all(ts), [](const team&a, const team&b){
        return a.score > b.score;
    });
    ts[0].rank = 1;
    int r = 1;
    loop(i, 1, ts.size()){
        if (ts[i - 1].score != ts[i].score) r++;
        ts[i].rank = r;
    }
    sort(all(ts), [](const team&a, const team&b){
        return a.id<b.id;
    });
    while (cin >> t){
        cout << ts[t - 1].rank << endl;
    }
}