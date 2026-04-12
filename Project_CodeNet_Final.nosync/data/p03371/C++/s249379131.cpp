#include <iostream>

using namespace std;

int a, b, c, x, y;
int cost;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> x >> y;
    if(x < y){
        swap(x, y);
        swap(a, b);
    }
    if(a + b > 2 * c){
        cost += 2 * c * y;
    }
    else{
        cost += (a + b) * y;
    }
    if(a > 2 * c){
        cost += 2 * c * (x - y);
    }
    else{
        cost += a * (x - y);
    }
    cout << cost << '\n';
    return 0;
}
