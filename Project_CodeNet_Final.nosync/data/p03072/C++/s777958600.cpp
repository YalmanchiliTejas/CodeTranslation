#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int f[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
            int flag=0;
        for(int j=1;j<i;j++){
            if(f[i]<f[j]){
                flag=1;
                break;
            }
        }
        if(!flag){
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
