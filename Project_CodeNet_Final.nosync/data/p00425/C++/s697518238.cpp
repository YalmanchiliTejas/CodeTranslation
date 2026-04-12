#include <bits/stdc++.h>

#define rep_(v, f, l) for (int v = (f), v##_ = (l); v < v##_; ++v)
#define rep(v, n) rep_(v, 0, n)
#define lep(v, n) rep_(v, 1, n + 1)
#define rrep_(v, f, l) for (int v = (l), v##_ = (f); v >= v##_; --v)
#define rrep(v, n) rrep_(v, 0, n - 1)
#define rlep(v, n) rrep_(v, 1, n)
#define show_a(a, size) rep(a##_it, size) std::cout << a[a##_it] << " \n"[a##_it == a##_it_ - 1];
#define show_v(v) show_a(v, v.size())
#define eachv(v, i) rep(i, v.size())
#define reachv(v, i) rrep(i, v.size())
#define debug(x) std::cerr << #x << " = " << x << "\n";

using namespace std;

typedef long long int lint;

struct Dice {
    int top;
    int side;
    int front;
    Dice(int top=1, int side=3, int front=2) : top(top), side(side), front(front) {}
    void set(int _top, int _side, int _front){
        top = _top;
        side = _side;
        front = _front;
    }
    void North(){set(front, side, 7 - top); }
    void East(){ set(7 - side, top, front); }
    void West(){ set(side, 7 - top, front); }
    void South(){set(7 - front, side, top); }
    void Right(){set(top, 7 - front, side); }
    void Left(){ set(top, front, 7 - side); }
    void cmd(const string& s){
        if (s == "North") North();
        if (s == "East") East();
        if (s == "West") West();
        if (s == "South") South();
        if (s == "Right") Right();
        if (s == "Left") Left();
    }
};

static inline int in(){ int x; scanf("%d", &x); return x; }
static inline lint inl(){ lint x; scanf("%lld", &x); return x; }

int main()
{
    int n;
    while (n = in()){
        int score = 0;
        Dice dice;
        rep(i, n){
            string s;
            cin >> s;
            dice.cmd(s);
            score += dice.top;
        }
        printf("%d\n", score + 1);
    }
    return (0);
}