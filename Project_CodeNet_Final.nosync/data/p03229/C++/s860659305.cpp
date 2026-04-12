#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,i;
    cin >> n;
    vector<long long> a(n);
    for(i=0;i<n;i++)cin >> a[i];

    sort(a.begin(), a.end());

    long long res = 0;
    long long res2 = 0;
    long long idx_small = 0;
    long long idx_large = n-1;

    vector<long long> p1(n);
    vector<long long>p2(n);
    p2[n-1] = -1;
    p1[n-1] = -1;

    for(i=1;i<n-1;i+=2){
        p2[i] = a[idx_small];
        p2[i+1] = a[idx_large];
        p1[i] = a[idx_large--];
        p1[i+1] = a[idx_small++];
    }
    p1[0] = a[idx_small];
    p2[0] = a[idx_large];
    if(p1[n-1]==-1)p1[n-1] = a[idx_large];
    if(p2[n-1]==-1)p2[n-1] = a[idx_small];

    for(i=0;i<n-1;i++){
        res += abs(p1[i]-p1[i+1]);
        res2 += abs(p2[i]-p2[i+1]);
    }
    cout << max(res,res2) << endl;
    return 0;
}
