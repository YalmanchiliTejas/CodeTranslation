#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> h(n);

    for(int i = 0;i<n;i++)
    {
        cin >> h[i];
    }

    int num_visible = 1;

    for(int i  = 1; i < n;i++)
    {
        bool visible=true;
        for(int j = 0; j < i;j++)
        {
            if(h[j] > h[i])
            {
                visible=false;
                break;
            }
        }
        if(visible)
        {
            num_visible+=1;
        }
    }
    cout << num_visible <<endl;
    return 0;
}