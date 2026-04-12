#include<iostream>
#include<vector>

#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;

using namespace std;

int main()
{
    int n;  cin >> n;
    vector<int> h(n);   rep(i, n) cin>> h[i];

    int view = h[0];
    int ans  = 1;
    for(int i = 1; i < n; i++){
        if(h[i] >= view){
            ans++;
            view = h[i];
        }
    }

    cout << ans << endl;
}