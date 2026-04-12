#include <iostream>
using namespace std;
int main(void)
{
    int N, H[20], sum = 1;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (H[j] > H[i])
            {
                break;
            }
            if (j == i - 1)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;

    return 0;
}