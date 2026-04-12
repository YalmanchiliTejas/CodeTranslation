#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=100010;
int arr[N];

int calc(int n) {
    vector<int> v(n+10, INT_MAX);
    v[0] = INT_MIN;
    int L[N];
    for (int i=0;i<n;i++)arr[i]*=-1;
    for (int i=0;i<n;i++) {
        auto it = upper_bound(v.begin(), v.end(), arr[i]);
        *it = arr[i];
        L[i] = it-v.begin();
    }
    return *max_element(L+1, L+n+1);
}
int main () {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>arr[i];
    
    cout<<calc(n);
    return 0;
}