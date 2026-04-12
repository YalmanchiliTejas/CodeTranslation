#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    pair<int,int> a[300000];
    int b[300000];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i].first=x;
        a[i].second=i;
    }
    sort(a,a+n);
    //return 0;
    for(int i=0;i<n/2;i++){
        b[a[i].second]=a[n/2].first;
    }
   // return 0;
    for(int i=n/2;i<n;i++){
        b[a[i].second]=a[n/2-1].first;
    }
   // return 0;
    for(int i=0;i<n;i++){
        cout<<b[i]<<endl;
    }
    return 0;
}