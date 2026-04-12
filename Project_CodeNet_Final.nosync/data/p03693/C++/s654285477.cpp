#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <iomanip>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){

//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());
    int r,g,b;
    cin >> r >> g >> b;

    string res = "NO";
    int sum = 100 * r + 10 * g + b;
    if(sum % 4 == 0)
    {
        res = "YES";
    }

    cout << res << endl;



    return 0;
}
