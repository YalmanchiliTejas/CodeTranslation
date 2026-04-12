#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define opt ios_base::sync_with_stdio(false); cin.tie(NULL);

void freak__()
{
    int n,i,j;
    cin >> n;
    int h[n],flag,cnt=0;
    for(i=0;i<n;i++) cin >> h[i];
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=0;j<i;j++)
        {
            if(h[j]>h[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) cnt++;
    }
    cout << cnt;
    cout << "\n";
}

int main()
{
    opt;
    freak__();
    return 0;
}