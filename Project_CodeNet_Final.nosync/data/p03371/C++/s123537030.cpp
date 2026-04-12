#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::pair;

using std::vector;
using std::sort;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans1=a*x+b*y;
    int ans2=(x>y)?c*y*2+a*(x-y)
                  :c*x*2+b*(y-x);
    int ans3=c*std::max(x,y)*2;
    cout << std::min({ans1,ans2,ans3}) << endl;
    return 0;
}

