#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    long long int res=0, m=1e9+7, currSum;
    cin>>n;
    vector<long long int> a(n);
    for(long long int& x: a)
        cin>>x;

    currSum=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        res=(res+((a[i]*currSum)%m))%m;
        currSum=((currSum+a[i])%m);
    }
    cout<<res<<endl;
    /*
    cout<<"BruteForce\n";
    res=0;
    for(i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            res=(res+(a[i]*a[j])%m)%m;
    cout<<res<<endl;
    */
    return 0;
}
