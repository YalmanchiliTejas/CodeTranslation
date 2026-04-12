#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> a(100000000);
    for(int i = 0; i < n; i++)cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        bool res = true;
        for(int j = i - 1; j >= 0; j--) {
            if(a[i] < a[j])res = false;
        }
        cnt += res;
    }
    cout << cnt << endl;
}