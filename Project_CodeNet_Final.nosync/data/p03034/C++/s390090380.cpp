#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;
long long int mpown(long long int m, int n);

int bitCount(int bits);
int main()
{
    int n;
    cin >> n;
    vector<long long int> s(n);
    for(int i=0;i<n;i++)cin >> s.at(i);
    long long int ans=0;
    for(int c=1;c<=n-1;c++){
        // int kup=(n-1)/(c+1);
        int kup;
        // int kup=n1c;
        if((n-1) %c ==0)
        {
            
                kup=min((n-1)/c-2,((n-1)/c-1)/2);}
        else{
            kup=(n-1)/c-1;
        }

        long long int tempf=0;
        for(int k=1;k<=kup;k++){
            tempf=tempf+s.at(n-1-k*c)+s.at(k*c);
            if(tempf>ans)ans=tempf;
        }
    }
    cout << ans << endl;
    return 0;
    // cout << ans << endl;
}

int bitCount(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555); //  2bitごとに計算
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333); //  4bitごとに計算
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f); //  8bitごとに計算
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff); //  16ビットごとに計算
    return (bits & 0x0000ffff) + (bits >> 16);             //  32ビット分を計算
}
long long int mpown(long long int m, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else
    {
        long long int temp = mpown(m, n / 2);
        return temp * temp * (n & 1 ? m : 1);
    }
}