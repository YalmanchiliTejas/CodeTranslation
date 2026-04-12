#include <iostream>

using namespace std;

int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    long long less = min(x,y);
    long long cost = 0;
    if((a+b)/2.0 > c) {
        cost += min(x,y)*c*2;
    } else {
        cost += min(x,y)*(a+b);
    }
    x -= less;
    y -= less;
    if(x == 0 && y == 0){
        cout << cost << endl;
        return 0;
    }
    if(x > 0) {
        if(a < c*2){
            cost += a*x;
        } else {
            cost += c*2*x;
        }
    }
    if(y > 0) {
        if(b < c*2){
            cost += b*y;
        } else {
            cost += c*2*y;
        }
    }
    cout << cost << endl;
    //case1 avg(a,b) > c
    //case2 avg(a,b) <= c
    //case3 a < c && x > y
    //case4 b < c && x < y
    return 0;
}
