#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;

    vector < int > a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    vector < int > ans(n+1);

    int cur=1;
    int x=1;
    for(int i=n;i>0;i-=2)
    {
        ans[cur++]=a[i];
        if(i==1)
            x=2;
    }

    for(int i=x;;i+=2)
    {
        if(cur>n)
            break;
        ans[cur++]=a[i];
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    cout<<endl;

    return 0;
}
