#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;++i)
        cin >> h[i];
    
    int cnt = 1;
    int max_h = h[0];
    for(int i=1;i<n;++i)
    {
        if(h[i] >= max_h)
        {
            cnt++;
            max_h = h[i];
        }
    }

    cout << cnt << endl;
    return 0;
}