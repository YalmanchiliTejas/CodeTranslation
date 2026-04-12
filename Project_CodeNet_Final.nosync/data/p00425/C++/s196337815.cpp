#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
#define repr(i ,n) for(int i=n;i>(int)(n);--i)
#define rep1(i ,n) for(int i=1;i<=(int)(n);++i)
#define ALL(a) a.begin(), a.end()
#define RSORT(a) sort(ALL(a),greater<>())
#define SORT(a) sort(ALL(a))
#define bit_check(bit, i) ((bit>>(i)) & 1)
#define PRINT(x) printf("%d\n",(x));
#define ENDL printf("\n");
using namespace std;
typedef long long int i64;
typedef unsigned long long u64;
template<class T> using V = vector<T>;
using VI = V<int>;
const int INF = 2e9;
const i64 MOD = 1e9 + 7;

template <class T> inline bool chmin(T& a, T b){if(a>b){a=b; return true;} return false;}
template <class T> inline bool chmax(T& a, T b){if(a<b){a=b; return true;} return false;}

struct D {
    int north();
    int south();
    int east();
    int west();
    void right();
    void left();
    void print(){
        cout << "t:" << top << " f:" << front << " bo:" << bottom << " ba:" << back << " r:" << rside << " l:" << lside << endl;
    }
    D(){
        this->top = 1;
        this->bottom = 6;
        this->front = 2;
        this->back = 5;
        this->rside = 3;
        this->lside = 4;
    };
        int front;
        int back;
        int rside;
        int lside;
        int top;
        int bottom;
};

int D::north(){
    int tmp = top;
    top = front; front = bottom; bottom = back; back = tmp;
    return top;
    }
int D::south(){
    int tmp = top;
    top = back; back = bottom; bottom = front; front = tmp;  
    return top;
}
int D::east(){
    int tmp = top;
    top = lside; lside = bottom; bottom = rside; rside = tmp;
    return top;
}
int D::west(){
    int tmp = top;
    top = rside; rside = bottom; bottom = lside; lside = tmp ;    
    return top;
}
void D::right(){
    int tmp = this->front;
    this->front = this->rside;
    this->rside = this->back;
    this->back = this->lside;
    this->lside = tmp;
    
}
void D::left(){
    int tmp = this->front;
    this->front = this->lside;
    this->lside = this->back;
    this->back = this->rside;
    this->rside = tmp;
}

signed main(){
    int n;
    while( cin >> n && n){
        vector<string> s(n);
        D d;
        rep(i ,n) cin >> s[i];
        int sum = 1;
        rep(i , n){
            if( s[i] == "North" ) sum += d.north();
            else if (s[i] == "South" ) sum += d.south();
            else if (s[i] == "East") sum += d.east();
            else if (s[i] == "West") sum += d.west();
            else if (s[i] == "Right") { sum += d.top; d.right(); }
            else if (s[i] == "Left") { sum += d.top; d.left(); }
            else fprintf( stderr , "error");
        }
        cout << sum << endl;
    }
}
