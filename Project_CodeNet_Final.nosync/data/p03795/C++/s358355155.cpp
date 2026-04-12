#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <bitset>
using namespace std;

int main() {
    int n;
    cin>>n;
    int x=n*800;
    int q=n/15;
    cout<<(x-q*200)<<endl;
    return 0;
}