#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    bool flag = true;
    int j = 0;
    int k = n-1;
    for(int i=n-1;i>=0;i--) {
        if(flag) {
            b[j] = a[i];
            j++;
            flag = false;
        }
        else {
            b[k] = a[i];
            k--;
            flag = true;
        }
    }
    for(int i=0;i<n;i++) {
        cout<<b[i]<<" ";
    }
    return 0;
}
