#include <bits/stdc++.h>
#include <map>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(a) (a).begin(), (a).end()
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int cnt = 0;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            if(s.at(j) == '#') cnt++;
            if(cnt == h + w){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
}
