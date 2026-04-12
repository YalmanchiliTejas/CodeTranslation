#include <bits/stdc++.h>

#define rep_(v, f, l) for (int v = (f); v < (l); ++v)
#define rep(v, n) rep_(v, 0, n)
#define lep(v, n) rep_(v, 1, n + 1)

using namespace std;

typedef long long int lint;

static inline int in(){ int x; scanf("%d", &x); return x; }
static inline lint inl(){ lint x; scanf("%lld", &x); return x; }

struct Team {
    int point;
    string name;
    Team(string name, int win, int lose, int draw) : name(name), point(win * 3 + draw) {}
    bool operator<(const Team& t){
        return point < t.point;
    }
};
bool operator<(const Team& a, const Team& b){
    return a.point < b.point;
}
bool operator>(const Team& a, const Team& b){
    return a.point > b.point;
}

int main()
{
    int n;
    bool space = false;
    while (n = in()){
        if (!space){
            space = true;
        }
        else puts("");

        vector<Team> ts;
        rep(i, n){
            string name;
            int win, lose, draw;
            cin >> name >> win >> lose >> draw;
            ts.push_back(Team(name, win, lose, draw));
        }
        stable_sort(ts.begin(), ts.end(), greater<Team>());
        rep(i, n){
            printf("%s,%d\n", ts[i].name.c_str(), ts[i].point);
        }
    }
    return (0);
}