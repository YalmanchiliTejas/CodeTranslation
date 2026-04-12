#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b>> c>> x>>y;
    vector<long> p;
    // 2i
    for (int i = 0; i <= ceil(1.0 * max(x,y)); ++i) {
        long sum = c * i *2;
        if(x - i > 0) {
            sum += (x-i)*a;
        }
        if(y - i > 0) {
            sum += (y-i)*b;
        }
        p.push_back(sum);
    }
    cout << *min_element(p.begin(), p.end()) << endl;
    return 0;
}
