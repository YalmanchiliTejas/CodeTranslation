#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int n, ans = 1;
    cin >> n;
    vector<int> h(n);
    for(int i = 0;i < n;i++){
        cin >> h[i];
    }
    
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(h[j] > h[i]){
                ans--;
                break;
            }
        }
        ans++;
    }

    cout << ans << "\n";

    return 0;
}