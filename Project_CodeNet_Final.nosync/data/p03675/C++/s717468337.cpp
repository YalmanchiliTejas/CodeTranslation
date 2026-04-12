#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#define INFI 987654321
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    list<int> lst;
    int N, dir = 1;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int here;
        cin >> here;
        if(dir == 1)
            lst.push_back(here);
        else
            lst.push_front(here);
        dir = -dir;
    }
    if(dir > 0) {
        for(auto iter = lst.begin(); iter != lst.end(); ++iter)
            printf("%d ", *iter);
    }
    else {
        for(auto iter = lst.rbegin(); iter != lst.rend(); ++iter)
            printf("%d ", *iter);
    }
    return 0;
}