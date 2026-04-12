#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    int ans = 800 * n - (n / 15) * 200;
    cout << ans << endl;
}
