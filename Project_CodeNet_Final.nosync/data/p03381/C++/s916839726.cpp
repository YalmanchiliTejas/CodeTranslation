#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i=0;i<n;i++)

signed main(void){
    int n;
    vector<int> x,y;
    cin>>n;
    REP(i,n){
        int temp;
        cin>>temp;
        x.push_back(temp);
        y.push_back(temp);
    }
    sort(y.begin(),y.end());
    int m1=y[n/2-1];
    int m2=y[n/2];
    for(int p : x){
        if (p<=m1)cout<<m2<<endl;
        else if(p>=m2)cout<<m1<<endl;
    }
}
