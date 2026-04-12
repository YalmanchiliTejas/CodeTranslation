#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp;
    int ans = 0;
    vector<int> h;
    int maxh = 0;
    h.push_back(0);
    for(int i=0; i < n; i++){
        cin >> tmp;
        h.push_back(tmp);
    }
    
    for(int i=0; i < n+1; i++){
        if(h[i] <= h[i+1] && maxh <= h[i+1]){
            maxh = max(maxh, h[i+1]);
            ans++;
        }else{
            maxh = max(maxh, h[i]);
        }
    }
    cout << ans << endl;
    return 0; 
}