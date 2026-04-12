#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
string a[55];
int ap[55][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<a[i].size();j++)
            ap[i][a[i][j]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        int kek=ap[1][i];
        for(int j=2;j<=n;j++)
            kek=min(kek,ap[j][i]);
        for(int j=1;j<=kek;j++)
            cout<<char(i+'a');
    }
    cout<<"\n";
    return 0;
}
/**

**/
