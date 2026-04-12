#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(void) {
int a, b, c, x, y;
long long p1, p2, p3;

std::cin >> a >> b >> c >> x >> y;

//少ない方までABを買う時
p1 = c*2*min(x,y) + a*(x-min(x,y)) + b*(y-min(x,y));


//多い方までABを買う時
p2 = c*2*max(x,y);


//そのまま買う時
p3 = a*x + b*y;


std::cout << min(p3,min(p1,p2)) << '\n';

return 0;
}
