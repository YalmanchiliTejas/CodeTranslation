#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<long, deque<long>, std::greater<long> > pq;
    long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    pq.push(a*x+b*y);
    pq.push(2*c*x+b*y);
    pq.push(a*x+2*c*y);
    pq.push(2*c*max(x,y));
    if (x >= y) pq.push(a*(x-y)+2*c*y);
    else pq.push(2*c*x+b*(y-x));
    cout << pq.top() << endl;
    return 0;
}