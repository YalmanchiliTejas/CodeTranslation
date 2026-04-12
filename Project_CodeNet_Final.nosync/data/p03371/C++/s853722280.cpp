#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
using ll = long long int;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    cin >> x >> y;

    if(a + b > 2*c){
        if(x > y){
            cout << min(2*c*y + a*(x-y), 2*c*x)<< endl;
        }else{
            cout << min(2*c*x + b*(y-x), 2*c*y) << endl;
        }
    }else{
        cout << a*x + b*y << endl;
    }

 }
