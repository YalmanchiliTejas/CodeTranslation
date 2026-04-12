#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,a,c=0,pre;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        if(i==0)pre=a,c=1;
        else
        {
            if(pre<=a)pre=a,c++;
        }
    }

    cout << c << "\n";


}
