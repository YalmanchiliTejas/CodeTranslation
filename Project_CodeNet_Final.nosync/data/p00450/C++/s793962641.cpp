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

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int, int> >g;
        for(int i=1; i <= n; i++){
            int s;
            cin >> s;
            if(i == 1) g.pb(mp(s, 1));
            else {
                if(i%2 == 0){
                    if(g[g.size()-1].first == s) g[g.size()-1].second++;
                    else{
                        g[g.size()-1].second = g[g.size()-1].second+1;
                        g[g.size()-1].first = (g[g.size()-1].first+1)%2;
                        if(g[g.size()-1].first == g[g.size()-2].first){
                            g[g.size()-2].second += g[g.size()-1].second;
                            g.pop_back();
                        }
                    }
                }else {
                    if(g[g.size()-1].first == s) g[g.size()-1].second++;
                    else g.pb(mp(s, 1));
                }
            }
        }
        int ans = 0;
        for(int i=0; i < g.size(); i++){
            if(g[i].first == 0) ans += g[i].second;
        }
        cout << ans << endl;
    }
}