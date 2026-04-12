#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <string>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sz[n];
    int shu=0;
    int max=-1;
    for(int i=0;i<n;i++)
    {
        cin>>sz[i];
        if(sz[i]>=max)
        {
            max=sz[i];
            shu++;
        }
    }
    cout<<shu<<endl;
    return 0;
}
