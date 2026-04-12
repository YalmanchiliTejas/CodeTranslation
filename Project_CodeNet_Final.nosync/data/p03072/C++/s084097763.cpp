#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int tmp;
    int count;
    vector<int> h;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        h.emplace_back(tmp);
    }
    tmp = h[0];
    count = 1;
    for (int i = 1; i < n; i++)
    {
        if (h[i] >= tmp)
        {
            count++;
            tmp = h[i];
        }
    }

    cout << count << endl;

    return 0;
}