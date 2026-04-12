#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int q;
    cin>>q;

    while(q--)
    {
        int key;
        cin>>key;

        cout<<(lower_bound(arr.begin(),arr.end(),key)-arr.begin())<<endl;
    }

    return 0;
}

