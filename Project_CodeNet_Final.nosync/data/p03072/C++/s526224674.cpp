#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;

    vector<int> height(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> height.at(i);
    }

    int counter, found = 1;
    ;
    int temp;
    int first = height.at(0);
    for (int i = height.size() - 1; i > 0; i--)
    {
        counter = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (height.at(i) >= height.at(j))
                counter++;
            if (counter == i)
                found++;
        }
    }
    cout << found << endl;

    return (0);
}