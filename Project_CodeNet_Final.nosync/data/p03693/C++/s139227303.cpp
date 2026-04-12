#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;



int main() {
    int r,g,b;

    cin>>r>>g>>b;

    int res = r*100+g*10+b;

    if(res%4 == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}
