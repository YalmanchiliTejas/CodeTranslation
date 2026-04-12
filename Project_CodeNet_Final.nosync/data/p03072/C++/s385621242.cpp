#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <string>
//typedef long long LL;
using namespace std;

int main(){
    int n;
    vector<int> h;
    int h_tmp;
    int ans = 1;
    int max;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> h_tmp;
        h.push_back(h_tmp);
    }
    max = h[0];
    for(int i=1; i<n; i++){
        if(h[i]>=max){
            ans++;
            max=h[i];
        }
    }
    cout << ans << endl;
}