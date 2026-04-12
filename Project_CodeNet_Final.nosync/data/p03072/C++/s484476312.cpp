#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int a[50];
int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int sum = 1, Max = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] >= Max) {
            Max = a[i];
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
