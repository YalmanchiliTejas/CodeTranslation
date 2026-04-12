#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_vector(vector<T> &vec)
{
    for (auto elem : vec)
    {
        cout << elem << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}
