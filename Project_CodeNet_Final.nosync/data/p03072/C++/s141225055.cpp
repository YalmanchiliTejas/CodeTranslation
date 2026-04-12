#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(A) A.begin(),A.end()
const long long mod=1000000007;
int main(){
    int h[30],ans=1;
    int n;bool flag=true;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>h[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(h[i]<h[j])
            flag=false;
        }
        if(flag==true)
        ans++;
        flag=true;
    }
    cout<<ans<<endl;
    return 0;
}