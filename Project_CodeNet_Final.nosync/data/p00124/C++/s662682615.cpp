#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
struct Team { string name; int score; };
bool cmp(const Team &a, const Team &b) { return a.score > b.score; }
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    bool flag = false;
    while(true)
    {
        int n; cin >> n;
        if(n == 0) break;
        if(flag) cout << endl;
        vector<Team> v(n);
        for(int i = 0; i < n; i++)
        {
            string name; cin >> name;
            int w, l, d; cin >> w >> l >> d;
            int s = w * 3 + d;
            v[i] = {name, s};
        }
        stable_sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++) cout << v[i].name << "," << v[i].score << endl;
        flag = true;
    }
    return 0;
}


