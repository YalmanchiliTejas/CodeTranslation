#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007
typedef long long ll;

int main() {
    int n;cin>>n;
    int cnt=1;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }
    int max=a[0];

    rep2(i,1,n){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i-1]<=a[i]&&max<=a[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

