#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define test long long int t; cin>>t; while(t-->0)
#define fIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
    fIO
    int n;
    cin>>n;
    int a[n];
    int c=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxh=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=maxh)
        {
            maxh=a[i];
            c++;
        }
        
    }
    cout<<c;
}