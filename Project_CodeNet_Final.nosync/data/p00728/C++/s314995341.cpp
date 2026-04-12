#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cin >> n;
    while (n != 0)
    {
        vector<int> s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int sum = 0;
        for(int i = 1; i < n - 1; i++){
            sum += s[i];
        }
        cout << sum / (n - 2) << endl;
        cin >> n;
    }
    
    return 0;
}
