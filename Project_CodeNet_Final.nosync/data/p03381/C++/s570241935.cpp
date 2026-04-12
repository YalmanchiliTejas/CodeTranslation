#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> x(n, 0);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    vector<int> x2;
    x2 = x;
    sort(x2.begin(), x2.end());
    
    int mid = (n / 2) - 1;
    
    for (int i = 0; i < n; ++i)
    {
        if (x[i] > x2[mid])
        {
            cout << x2[mid] << endl;
        }
        else
        {
            cout << x2[mid + 1] << endl;
        }
    }
    
    
    return 0;
}