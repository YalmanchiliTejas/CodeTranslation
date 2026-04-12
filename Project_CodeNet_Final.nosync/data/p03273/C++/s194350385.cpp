#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    char a[h+1][w+1];
    int nr[h+1]={0};
    int nc[w+1]={0};
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
            {
                nr[i]++;
                nc[j]++;
            }
        }
    }
    for(int i=1;i<=h;i++)
    {
        if(nr[i]!=w)
        {
            for(int j=1;j<=w;j++)
            {
                if(nc[j]!=h)
                {
                    cout<<a[i][j];
                }
            }
            cout<<"\n";
        }

    }
}
