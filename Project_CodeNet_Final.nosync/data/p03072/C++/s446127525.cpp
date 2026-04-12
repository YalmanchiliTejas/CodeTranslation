#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

#define ll long long
#define endl endl
using namespace std;

const int INF = 0x3f3f3f3f;
int arr[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ans=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int m = arr[0];
    for(int i=0; i<n; i++)
    {
        m = max(m, arr[i]);
        if(arr[i] >= m) ans++;
    }
    cout << ans;

}

