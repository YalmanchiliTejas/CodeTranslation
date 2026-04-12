#include <iostream>

using namespace std;

int main()
{
    int n,res,a[100],temp_max_height;
    res = 1;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) cin >> a[i];
    temp_max_height = a[0];
    for (int i = 1 ; i < n ; i ++)
    {
        if (a[i] >= temp_max_height)
        {
            temp_max_height = a[i];
            res++;
        }
    }
    cout << res;

}
