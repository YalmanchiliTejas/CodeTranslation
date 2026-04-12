#include <bits/stdc++.h>
#define  rep(i,n) for (int i=0;i<n;i++)
using namespace std;

int main(){
    while (true){

        int n;
        cin>>n;
        if (n==0) break;
        vector<int> v(n,0);
        int sum=0;
        rep(i,n) {
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        cout<<(sum-v[0]-v[n-1])/(n-2)<<endl;

    }
    return  0;
}
