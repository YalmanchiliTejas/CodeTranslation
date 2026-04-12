#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>
#include <cmath>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;

    for(int i = 0; i < 1e5; ++i)
    {
        if(x < y*i + z * (i+1))
        {
            cout << i - 1 << endl;
            return 0;
        }
    }

    return 0;    
}

