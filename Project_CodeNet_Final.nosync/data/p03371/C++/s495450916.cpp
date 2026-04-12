/*
Problem

Category
全探索・全列挙

URL:
https://atcoder.jp/contests/abc095/tasks/arc096_a


考察:

Date: 2020/03/31
*/

#include <bits/stdc++.h>
// #include "../utils.cpp"
using namespace std;
// #define int long long

/* ==== declarations ====== */
// functions
void solve();
void getInput();

// global variables
int a, b, c, x, y;

/* ======================== */

int main(){
    getInput();
    solve();
    return 0;
}

void getInput() {
    cin>>a>>b>>c>>x>>y;
}

void solve() {
    c *=2;
    int nc = 0;
    // cout<<"a, b, c: "<<a<<", "<<b<<", "<<c<<endl;
    // cout<<"x, y: "<<x<<", "<<y<<endl;
    if (c < a) {
        nc += x;
        x = 0;
        y -= nc;
        if (y <= 0) {
            cout<<nc*c<<endl;
            return;
        }
    }
    if (c < b) {
        nc += y;
        x -= nc;
        y = 0;
        if (x <= 0) {
            cout<<nc*c<<endl;
            return;
        }
    }

    while(x > 0 and y > 0) {
        if (a + b < c) break;
        
        nc++;
        x--;
        y--;
    }
    cout<<x*a+y*b+nc*c<<endl;
    // cout<<"x, y, nc: "<<x<<", "<<y<<", "<<nc<<endl;
    


    // cout<<c<<endl;
}