#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];

    int ans=1;
    int hmax=h[0];
    for(int i=1;i<n;i++){
        if(hmax<=h[i]){
            ans++;
            hmax=h[i];
        }
    }
    cout << ans << endl;
}