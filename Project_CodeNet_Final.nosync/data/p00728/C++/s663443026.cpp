#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int sum = 0;
        int mini = 10000000;
        int maxi = 0;
        for(int c=0;c<n;c++)
        {
            int z;
            cin>>z;
            mini = min(mini,z);
            maxi = max(maxi,z);
            sum += z;
        }
        cout<<(sum-mini-maxi)/(n-2)<<endl;
    }
}