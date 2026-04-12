#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define For(i, a, b) for(int i = (a); i < (b); i++)
#define Rep(i, n) For(i, 0, (n))
#define Rrep(i, n) for(int i = (n - 1); i >= 0; i--)
#define pb push_back

const int inf = 999999999;
const int mod = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    int a, b, c; cin >> a >> b >> c;
    if((a * 100 + b * 10 + c) % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}