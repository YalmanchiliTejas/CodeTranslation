#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define MAXSIZE 200
#define MAXL 100
typedef long long int lli;

int main(){
    int n;
    cin >> n;
    int ans = 0, maxh = 0;
    for(int i = 0; i != n; ++i){
        int h;
        cin >> h;
        
        if(max(h, maxh) == h) ans += 1;

        maxh = max(h, maxh);
    }
    cout << ans << endl;
    return 0;
}