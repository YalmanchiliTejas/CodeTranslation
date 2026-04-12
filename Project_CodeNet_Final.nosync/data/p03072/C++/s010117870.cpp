#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(void)
{
    int  n;
    cin >> n;
    vector<int> h(n);
    for(auto i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    
    int maxh = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if (h[i] >= maxh) {
            count++;
            maxh = h[i];
        }
    }
    
  
    cout << count << endl;
    return 0;
}