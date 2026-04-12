#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    

    long long k,a,b;
    cin >> k >> a >> b;
    if(a <= b){
        if(k <= a){
            cout << 1 << endl;
        }else{
            cout << -1 << endl;
        }
    }else{
        if( k<=a){
            cout << 1 << endl;
        }
        else if((k-a)%(a-b) == 0){
            cout << 2 * ((k-a) / (a-b)) + 1 << endl;
        }else{
            cout << 2 * ((k-a) / (a-b) + 1) + 1 << endl;
        }

    }
}