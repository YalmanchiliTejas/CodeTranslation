#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin >> height[i];

    int maxh = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
        if(maxh<=height[i]){
            ans++;
            maxh = height[i];
        }
    }
    cout << ans << endl;
}