#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,max=0,j,i;
    bool done;
    cin >> n;
    int h[21];
    for(i=0;i<n;i++)
    {
        done = true;
        cin >> h[i];
        for(j=0;j<i;j++)
        {
            if(h[i]<h[j])
            {
                done = false;
                break;
            }

        }
        if(done)max++;
    }
    cout << max << endl;
    return 0;
}

