#include <bits/stdc++.h>
using namespace std;
#define ll long long
int modulo(int x,int N){
    return (x % N + N) %N;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    reverse(a,a+n);
    for(int i=0;i<n;++i)
    {
        bool check=true;
        for(int j=i+1;j<n;++j)
        {
            if(a[i]>=a[j])
            {
                check = true;
            }
            else {check=false; break;}
        }
        if(check) ans++;
    }
    cout<<ans;
}
