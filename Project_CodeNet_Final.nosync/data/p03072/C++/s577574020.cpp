#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    int ans = N;
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (H[i] < H[j])
            {
                ans--;
                break;
            }
        }
        
    }
    cout << ans;
    return 0;
}