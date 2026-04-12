#include<bits/stdc++.h>

using namespace std;
int main()
{

    int n,p;
    cin >> n;
    int cnt=n;
    int arr [n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i < n; i++)
    {
        p = arr[i];
        for(int j = 0; j <= i; j++)
        {
            if( p < arr[j])
            {
                cnt--;
                break ;
            }

        }
    }
    cout << cnt << endl;
return 0;
}
