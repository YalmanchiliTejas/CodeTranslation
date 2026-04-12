#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        x[i] = {temp, i};
    }
    sort(x.begin(), x.end());
    vector<int> result(n);
    for(int i = 0; i < n; i++)
    {
        if(i < n / 2)
        {
            result[x[i].second] = x[n / 2].first;
        }else{
            result[x[i].second] = x[(n / 2) - 1].first;
        }
    }
    for(auto e : result)
    {
        cout << e << endl;
    }
    return 0;
}
