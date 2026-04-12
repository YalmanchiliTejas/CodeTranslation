

#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >>  n;

    int x[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int  cnt = 0, ch = 0;

    for(int i = 0; i < n; i++)
    {
         ch = 0;
        for(int j = 0; j < i; j++)
        {
           if(x[i] < x[j])
           {

               ch = 1;
               break;
           }

        }

        if(!ch)
           cnt++;
    }

    cout << cnt << endl;

    return 0;
}
