
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    
    string ans = "No";
    if (N == M) ans = "Yes";
    
    // 出力
    cout << ans << endl;
    
}