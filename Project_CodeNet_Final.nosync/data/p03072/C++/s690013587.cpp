#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> m(n);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[i] = x;
    }
    int max = m[0];
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if (m[i] >= max) {
            count++;
            max = m[i];
        }
    }
    cout << count << "\n";
}