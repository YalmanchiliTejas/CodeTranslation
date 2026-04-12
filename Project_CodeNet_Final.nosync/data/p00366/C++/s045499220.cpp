#include<iostream>
#include<vector>
using namespace std;

int N, t[100100], mx;
vector<int> v;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t[i];
        mx = max(mx, t[i]);
    }
    for(int i = 1; i <= mx; i++){
        if(mx % i == 0){
            v.push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += *lower_bound(v.begin(), v.end(), t[i]) - t[i];
    }
    cout << ans << endl;

    return 0;
}

