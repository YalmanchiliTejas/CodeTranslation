#include <bits/stdc++.h>
using namespace std;

int main(){

    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        vector<int> s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }

        sort(s.begin(), s.end());

        int sum = accumulate(s.begin(), s.end(), 0);

        sum -= (s[0] + s[n - 1]);

        int ans = sum / (n - 2);
        cout << ans << endl;
    }

    return 0;
}
