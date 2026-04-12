#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;
#define ll long long

ll INF = 1e9 + 7;
const int N = 1e5 + 7;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<ll> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll sum = 0;
    ll prod = 0;

    for(int i=0;i<n;i++)
    {
        prod = (prod + sum * arr[i]) %INF;
        sum = (sum + arr[i]) %INF;
    }

    cout<<(prod + INF)%INF<<endl;
}
