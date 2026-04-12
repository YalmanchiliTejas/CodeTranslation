#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long llu;

using namespace std;

int main() {
    FIO
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    if(n == 1)
    {
        cout<<arr[0];
    }
    else if(n&1)
    {
        for(int i=n-1; i>=0; i-=2)
            cout<<arr[i]<<" ";
        for(int i=1; i<n; i+=2)
            cout<<arr[i]<<" ";
    }
    else
    {
        for(int i=n-1; i>=0; i-=2)
            cout<<arr[i]<<" ";
        for(int i=0; i<n; i+=2)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
