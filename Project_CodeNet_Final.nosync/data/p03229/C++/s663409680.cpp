#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int p1 = 1, p2 = n-1;
    long long ans = 0;
    int left = a[0] , right = a[0];
    bool turn = 0;
    while(1)
    {
        turn  = !turn;
        if(turn)
        {
            if(p1<=p2)
            {
                ans += abs(a[p2] - left);
                left = a[p2];
                p2--;
            }else break;
            if(p1<=p2)
            {
                ans += abs(a[p2] - right);
                right = a[p2];
                p2--;
            }else break;
        }else
        {
            if(p1<=p2)
            {
                ans += abs(a[p1] - left);
                left = a[p1];
                p1++;
            }else break;
            if(p1<=p2)
            {
                ans += abs(a[p1] - right);
                right = a[p1];
                p1++;
            }else break;
        }
    }
    p1 = 0, p2 = n-2;
    long long ans1 = 0;
    left = a[n-1] , right = a[n-1];
    turn = 1;
    while(1)
    {
        turn  = !turn;
        if(turn)
        {
            if(p1<=p2)
            {
                ans1 += abs(a[p2] - left);
                left = a[p2];
                p2--;
            }else break;
            if(p1<=p2)
            {
                ans1 += abs(a[p2] - right);
                right = a[p2];
                p2--;
            }else break;
        }else
        {
            if(p1<=p2)
            {
                ans1 += abs(a[p1] - left);
                left = a[p1];
                p1++;
            }else break;
            if(p1<=p2)
            {
                ans1 += abs(a[p1] - right);
                right = a[p1];
                p1++;
            }else break;
        }
    }
    ans=max(ans,ans1);
    cout<<ans<<endl;
}