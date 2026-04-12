#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    //AとBのみ
    ll sum1 = A*X+B*Y;
    //ABのみ
    ll sum2 = 2*C*max(X,Y);
    //ABの最大数とA,B
    ll sum3 = 0;
    sum3 += 2*C*min(X,Y);
    ll af_X = X - min(X,Y);
    ll af_Y = Y - min(X,Y);
    sum3 += af_X * A + af_Y * B;

    cout << min(sum1,min(sum2,sum3)) << endl;




    return 0;
}
