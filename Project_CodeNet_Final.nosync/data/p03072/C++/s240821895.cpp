#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> H;

    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        H.push_back(h);
    }

    int count = 0;
    int tmp = 0;

    for (int i = 0; i < N; i++)
    {
        if (tmp <= H[i])
        {
            count += 1;
        }
        tmp = max(tmp, H[i]);
    }
    cout << count << endl;
}