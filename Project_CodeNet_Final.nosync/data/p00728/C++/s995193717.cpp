#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
 
using namespace std;
 
int main()
{
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        int max = -1, min = 10000, sum = 0, score = 0, ans = 0;
        for(int i = 0; i < n; i++){
            cin >> score;
            sum += score;
            if(score > max) max = score;
            if(score < min) min = score;
        }
        sum -= max + min;
        ans = sum / (n - 2);
        cout << ans << endl;
    }
    return 0;
}