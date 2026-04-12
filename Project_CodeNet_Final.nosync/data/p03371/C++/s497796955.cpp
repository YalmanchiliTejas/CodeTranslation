#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main(){
    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    int sum = a*x+b*y, m1, m2;

    m1 = c * (max(x, y) * 2);

    m2 = c * (min(x, y) * 2);
    if(x > y) m2 += a*(x-y);
    else m2 += b*(y-x);

    cout << min(sum, min(m1, m2)) << endl;
}