#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int num_input;
    int ind;
    int n_half;

    vector<int> num;
    vector<int> ans;

    cin >> n;
    n_half = n / 2;

    for (int i = 0; i < n; i++)
    {
        cin >> num_input;
        num.push_back(num_input);
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(0);
    }

    ans[n_half] = num[0];

    for (int i = 1; i < n; i++)
    {
        if (n % 2 == 0)
        {
            if (i % 2 == 0)
            {
                ind = i;
            }
            else
            {
                ind = -i;
            }
        }

        else
        {
            if (i % 2 == 0)
            {
                ind = -i;
            }
            else
            {
                ind = i;
            }
        }

        ans[n_half += ind] = num[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}