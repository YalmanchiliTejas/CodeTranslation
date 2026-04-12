#include <iostream>
#include <vector>
using namespace std;

const int N = 205;
int n, a[N];
vector<int> ans;

bool sorted(int n, int a[])
{
    for (int i = 0; i < n-1; i++)
        if (a[i] > a[i+1])
        return 0;
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while(!sorted(n,a))
    {
        if (a[0] < a[n-1] && a[n-1] != n-1)
        {
            ans.push_back(n-1);
            swap(a[0],a[n-1]);
        }
        ans.push_back(1);
        for (int i = 0; i < n-1; i++)
        {
            swap(a[i],a[i+1]);
        }
    }
    cout << ans.size() << endl;
    for (auto x: ans)
        cout << x << endl;
}
