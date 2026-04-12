#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define saken string
#define erba continue
using namespace std;

int n, m;
map < pair <int, int>, bool > mp;
string s[10];
bool check = 0;

void rec(int x, int y) {

    if(check) {return;}


    if(x == n && y == m) {mp[mper(x, y)] = 1; return;}


    int cnt = 0;

    if(s[x][y - 2] == '#' && !mp[mper(x, y - 1)]) {cnt++;}
    if(s[x][y] == '#' && !mp[mper(x, y + 1)]) {cnt++;}
    if(s[x + 1][y - 1] == '#' && !mp[mper(x + 1, y)]) {cnt++;}
    if(s[x - 1][y - 1] == '#' && !mp[mper(x - 1, y)]) {cnt++;}

    if(cnt != 1) {check = 1; return;}


    mp[mper(x, y)] = 1;

    if(s[x][y] == '#' && !mp[mper(x, y + 1)]) {rec(x, y + 1);}
    else if(s[x + 1][y - 1] == '#' && !mp[mper(x + 1, y)]) {rec(x + 1, y);}
    else {check = 1;return;}

}

int main(){

mal

cin >> n >> m;

for(int i = 1; i <= n; ++i) {
    cin >> s[i];
}

if(s[1][0] != '#') {cout << "Impossible";return 0;}

rec(1, 1);

if(check) {cout << "Impossible";return 0;}

for(int i = 1; i <= n; ++i) {

    for(int j = 1; j <= m; ++j) {

        if(s[i][j - 1] == '#' && !mp[mper(i, j)]) {cout << "Impossible";return 0;}

    }

}

cout << "Possible";

return 0;
}

