        #include <bits/stdc++.h>
        #include<iostream>
        #include<algorithm>
        #include<set>
        #include<map>
        #include<math.h>
        //#include <ttmath.h>
        #define endl '\n'
        #define modulo 1000000007
        #define int long long
        #pragma GCC optimize("-Ofast")
        #define float double
        #define PI 3.141592653589793238462643
        #define sinDegrees(x) sin((x) * PI / 180.0)
        #define tanDegrees(x) tan((x) * PI / 180.0)
        #define atanDegrees(x) atan(x)* 180.0 / PI
        using namespace std;
        int power(int x,int y)
        {
        int temp;
        if(y == 0)
        return 1;
        temp = (power(x, y/2))%modulo;
        if (y%2 == 0)
        return ((temp%modulo)*temp)%modulo;
        else
        return ((x*temp%modulo)*temp)%modulo;
        }
        int inv(int x)
        {
        return (power(x,modulo-2)+modulo)%modulo;
        }
        /*#include "testlib.h"
        int main(int argc, char* argv[])
        {
        iostream::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        registerGen(argc, argv, 1);
        int n,k;
        n=rnd.next(1,50);
        k=rnd.next(1,n);
        cout<<n<<' '<<k;
        }*/
        bool comp(pair<int,int>a,pair<int,int> b)
        {
            return a.second>b.second;
        }
        int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] < key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LDS(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        // new smallest value
        if (v[i] > tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] <= tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming grater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
        tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }
        return length;
        }
        int32_t main()
        {
            //freopen("output.txt","w", stdout);
            //freopen("input4.txt","r", stdin);
            iostream::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int n,buff;
            cin>>n;
            vector<int>lolz;
            for(int i=0;i<n;i++){
            cin>>buff;
            lolz.push_back(buff);
            }
            cout<<LDS(lolz);
            return 0;
        }
