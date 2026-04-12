#include<bits/stdc++.h>
#define rev(a,b){return a>b}
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
int arr[25];




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int maxtill = arr[0];
    int ans = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=maxtill)
        {
            ans++;
            maxtill = arr[i];
        }
    }
    cout<<ans<<endl;
}
