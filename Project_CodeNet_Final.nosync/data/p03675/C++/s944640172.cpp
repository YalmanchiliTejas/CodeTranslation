#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector <int> v;
    for (int i = N - 1; i >= 0; i -= 2)
        v.push_back(arr[i]);
    for (int i = N % 2; i < N; i += 2)
        v.push_back(arr[i]);

    for (int x : v)
        cout << x << " ";
    cout << "\n";
}