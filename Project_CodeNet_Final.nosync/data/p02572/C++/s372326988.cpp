#include <bits/stdc++.h>
using namespace std;

int main(){
    long long inf = pow(10,9)+7;
    int n;
    cin>>n;
    vector<long long> a(n);
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    long long ans = 0;
    long long his = 0;
    for(int i=0;i<n;i++){
        his += a[i];
        long long tmp = a[i] * ((sum-his)%inf);
        tmp = tmp%inf;
        ans = (ans+tmp)%inf;
    }
    cout<<ans<<endl;
    return 0;
}