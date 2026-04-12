#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[30];
    for(int i=1;i<=n;i++) cin>>a[i];
    int t=a[1],m=1;
    for(int i=2;i<=n;i++){
        if(a[i]>=t){
            t=a[i];
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}
