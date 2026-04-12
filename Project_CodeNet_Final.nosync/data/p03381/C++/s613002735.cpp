#include <bits/stdc++.h>

using namespace std;
#define N 2005
vector<int>a;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector<int>b=a;
    sort(a.begin(),a.end());
    int m1=a[n/2-1];
    int m2=a[n/2];
    for(int i=0;i<n;++i){
        if(b[i]>=m2){
            cout<<m1<<endl;
        }
        else cout<<m2<<endl;
    }

    return 0;
}
