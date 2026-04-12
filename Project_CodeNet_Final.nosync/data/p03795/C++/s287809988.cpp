#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using Pos = std::pair<int, int>;
//cout<<fixed<<std:cout<<fixed<<setprecision(2)<<Max<<endl;


int main() {
    int N;
    cin>>N;

    cout<<800*N-(int)(N/15)*200<<endl;

    return 0;
}