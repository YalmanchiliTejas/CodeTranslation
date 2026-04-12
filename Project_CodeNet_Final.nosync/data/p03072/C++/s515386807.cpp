#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
ll mod=1000000007;

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int ans=1,ma=ar[0];
    for(int i=1;i<n;i++){
        if(ar[i]>=ma){
            ma=ar[i];
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
