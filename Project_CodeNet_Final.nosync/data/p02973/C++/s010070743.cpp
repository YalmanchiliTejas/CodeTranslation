#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i != n; ++i)
        cin >> arr[i];
    
    vector<int> tmp(1, arr[0]);
    for (int i = 1; i != n; ++i)
    {
        int l = -1;
        int r = tmp.size();
        
        while (r - l != 1)
        {
            int m = l + r >> 1;
            
            if (tmp[m] >= arr[i])
                l = m;
            else
                r = m;
        }
        
        if (r == tmp.size())
            tmp.push_back(arr[i]);
        else
            tmp[r] = max(tmp[r], arr[i]);
    }
    
    cout << tmp.size() << '\n';
    
    return 0;
}