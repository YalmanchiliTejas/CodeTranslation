#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(m<n)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}

