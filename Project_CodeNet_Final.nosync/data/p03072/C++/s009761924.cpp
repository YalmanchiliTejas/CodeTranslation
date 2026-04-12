#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int N;

int H[21];

int cnt;

int ans=1;

int main()
{
    cin >> N;

    rep(i,N)cin >> H[i];

    for(int i=N-1;i>=1;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(H[i]<H[j])
            {
                cnt++;
            }
        }

        if(cnt==0)ans++;

        cnt=0;
    }

    cout << ans << endl;


    return 0;
}