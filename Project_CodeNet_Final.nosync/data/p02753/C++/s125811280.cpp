#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long
#define pi 3.141592653589793238462643383279502
#define M 1000000007
#define F first
#define S second
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
int findXor(int arr[], int n)
{

    // Calculate xor of all the elements
    int xoR = 0;
    for (int i = 0; i < n; i++) {
        xoR = xoR ^ arr[i];
    }

    // Return twice of xor value
    return xoR * 2;
}

signed main()
{
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='A')
            a++;
        else
            b++;
    }
    if(a==0||b==0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}



