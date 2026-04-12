#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ALL(T) T.begin(), T.end()
#define SCORE first
#define TEAM second.second

using namespace std;

typedef pair<int, pair<int, string> > piis;

int main(void){
    for(int n, end = 0; cin >> n, n;){
        if(end ++) cout << endl; 
        vector<piis> table;
        while(n --){
            int w, l, d;
            string team;
            cin >> team >> w >> l >> d;
            table.push_back(make_pair(3 * w + d, make_pair(n, team)));
        }
        sort(ALL(table), greater<piis>());

        rep(i, table.size())
            cout << table[i].TEAM << ',' << table[i].SCORE << endl;
    }

}