#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n,a;
    vector<int>v;
    vector<int>::iterator l;
    int ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a;
        if(v.size()==0)
        {
            ans++;
            v.push_back(a);
        }
        else
        {
            l=upper_bound(v.begin(),v.end(),a,greater<int>());
            j=l-v.begin();
            if(j==ans)
            {
                ans++;
                v.push_back(a);
            }
            else
            {
                v[j]=a;
            }
        }
    }
    cout << ans << endl;
}

