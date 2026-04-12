#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxHeight(vector<int>::iterator begin , vector<int>::iterator end)
{
    int ret = 0;
    while (begin != end)
    {
        ret = max(ret, *begin);
        begin++;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (auto& height : heights)
    {
        cin >> height;
    }

    int count = 0;
    for (int i=0; i < heights.size(); i++)
    {
        if (maxHeight(heights.begin(), heights.begin()+i+1) == heights[i])
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}