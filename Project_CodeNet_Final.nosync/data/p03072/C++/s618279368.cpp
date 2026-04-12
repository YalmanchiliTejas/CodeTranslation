#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int high[n];
    for(int i=0; i<n; i++){
        cin >> high[i];
    }
    int M=high[0];
    int ans=1;
    for(int i=1; i<n; i++){
        if(M<=high[i]){
            ans++;
            M=high[i];
        }
    }
    cout << ans;

    return 0;
}