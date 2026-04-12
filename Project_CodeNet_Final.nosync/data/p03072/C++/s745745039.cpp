#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main() {
    int ans=1;
    int n;
    cin>>n;
    int b;
    cin>>b;
    int ma=b;
    for(int i=1;i<n;i++){
        cin>>b;
        if(b>=ma){
            ans++;
            ma=b;
        }
    }
    cout<<ans<<endl;
}