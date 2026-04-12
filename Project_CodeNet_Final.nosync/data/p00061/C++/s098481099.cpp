#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

bool compare(const P& e1, const P& e2) {
    return(e1.second > e2.second);
}

int main(void) {
    int num, score;
    vector<P> v;
    map<int, int> m;
    while(scanf("%d,%d", &num, &score), num||score) {
        v.push_back(P(num, score));
    }
    sort(v.begin(), v.end(), compare);
    
    int rank = 0, before = -1;
    for(int r = 0; r < v.size(); r++) {
        if(v[r].second != before) rank++;
        before = v[r].second;
        m[v[r].first] = rank;
        //if(r + 1 < v.size() && v[r].second != v[r + 1].second) rank++;
    }
    int n;
    while(cin >> n) {
        cout << m[n] <<endl;
    }
    return(0);
}