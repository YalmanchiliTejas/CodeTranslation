#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

bool pairCompare(const std::pair<string, int>& firstElem, const std::pair<string, int>& secondElem) {
    return firstElem.second > secondElem.second;
}

int main(){
    int n;
    bool isFirst = true;
    while(cin >>  n, n){
        if(!isFirst) cout << endl;

        vector<pair<string, int> > team;

        for(int i=0; i < n; i++){
            string name; int p, q, r;
            cin >> name >> p >> q >> r;
            team.pb(mp(name, 3*p+r));
        }

        sort(all(team), pairCompare);

        for(int i=0; i < team.size(); i++){
            cout << team[i].first << "," << team[i].second << endl;
        }

        isFirst = false;
    }
}