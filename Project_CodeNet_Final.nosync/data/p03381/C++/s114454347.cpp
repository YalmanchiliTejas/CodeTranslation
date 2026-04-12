#include <iostream>
#include <algorithm>
#define MAX 200005
using namespace std;

int n;
pair <int,int> y[MAX];
int rez[MAX];
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>y[i].first;
        y[i].second=i;
    }

    sort(y+1,y+n+1);
    for (int i=1; i<=n; i++)
    {
        if (i<=n/2)
            rez[y[i].second]=y[n/2+1].first;
        else
            rez[y[i].second]=y[n/2].first;
    }
    for (int i=1; i<=n; i++)
        cout<<rez[i]<<"\n";

    return 0;
}
