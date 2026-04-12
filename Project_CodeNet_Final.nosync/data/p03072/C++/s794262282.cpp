#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> height;
    int n;
    cin >> n;

    for(int i = 0 ; i < n; ++i)
    {
        int h;
        cin >> h;
        height.push_back(h);
    }
    int count = 1;
    int min_height = height[0];
    for(int i = 0 ; i < height.size(); ++i)
    {
        int j = i+1;

        if(height[j] >= height[i] && height[j] >= min_height)
        {
            count++;
        }
        min_height = max(min_height, height[j]);
    }

    cout << count << endl;

    return 0;
}
