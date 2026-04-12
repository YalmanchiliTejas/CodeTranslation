#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <string>
#include <limits.h>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<tuple<int, int, int>> x;

deque<pair<int, pair<int, int>>> p;

bool xx(tuple<int, int, int> &lhs, tuple<int, int,int> &rhs){
    return get<1>(lhs) < get<1>(rhs);
}

set<int> contain;

vector<int> uf;

int find(int x){
    if(uf[x] == x){
        return x;
    }else{
        return uf[x] = find(uf[x]);
    }
}

void unio(int x, int y){
    uf[find(x)] = uf[find(y)];
}

map<pair<int, int>, int> costs;

pair<int, int> mp(int x, int y){
    if (x < y) {
        return make_pair(x, y);
    }else{
        return make_pair(y, x);
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int xx,yy;
        cin >> xx >> yy;
        x.push_back(make_tuple(xx, yy,i));
    }
    
    for (int i = 0; i < n; i++) {
        uf.push_back(i);
    }
    

    sort(x.begin(), x.end());
    
    for (int i = 0; i < n-1; i++) {
        int cost = min(abs(get<0>(x[i]) - get<0>(x[i+1])) , abs(get<1>(x[i])-get<1>(x[i+1])));
        p.push_back(make_pair(cost, make_pair(get<2>(x[i]), get<2>(x[i+1]))));
    }
    
    sort(x.begin(), x.end(),xx);
    
    for (int i = 0; i < n-1; i++) {
        int cost = min(abs(get<0>(x[i]) - get<0>(x[i+1])) , abs(get<1>(x[i])-get<1>(x[i+1])));
        p.push_back(make_pair(cost, make_pair(get<2>(x[i]), get<2>(x[i+1]))));
    }
    
    sort(p.begin(), p.end());
    
    int sum = 0;
    for (int i = 1; i < n;) {
        auto mm = p.front();
        if(find(mm.second.first) != find(mm.second.second)){
            unio(mm.second.first, mm.second.second);
            sum += mm.first;
            i++;
        }
        p.pop_front();
    }
    
    cout << sum << endl;
    return 0;
}
