#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <deque>
using namespace std;

int main()
{
    int n, a[100010], c=1,idb, ids=1;
    long long ans1=0, ans2=0;
    bool big=false;
    deque<int> deq1, deq2;
    cin>>n;
    idb=n-1;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    deq1.push_back(a[0]);
    while (c!=n)
    {
        big=!big;
        if (big==true)
        {
            if (c==n-1)
            {
                if (abs(deq1[0]-a[idb])>=abs(deq1[deq1.size()-1]-a[idb])) deq1.push_front(a[idb]);
                else deq1.push_back(a[idb]);
                c++;
                idb--;
            }
            else
            {
                deq1.push_front(a[idb]);
                idb--;
                deq1.push_back(a[idb]);
                idb--;
                c+=2;
            }
        }
        else
        {
            if (c==n-1)
            {
                if (abs(deq1[0]-a[ids])>=abs(deq1[deq1.size()-1]-a[ids])) deq1.push_front(a[ids]);
                else deq1.push_back(a[ids]);
                c++;
                ids++;
            }
            else
            {
                deq1.push_front(a[ids]);
                ids++;
                deq1.push_back(a[ids]);
                ids++;
                c+=2;
            }
        }
    }
    for (int i=0; i<n-1; i++) ans1+=abs(deq1[i+1]-deq1[i]);

    ids=0; idb=n-2; big=true; c=1;
    deq2.push_back(a[n-1]);
    while (c!=n)
    {
        big=!big;
        if (big==true)
        {
            if (c==n-1)
            {
                if (abs(deq2[0]-a[idb])>=abs(deq2[deq2.size()-1]-a[idb])) deq2.push_front(a[idb]);
                else deq2.push_back(a[idb]);
                c++;
                idb--;
            }
            else
            {
                deq2.push_front(a[idb]);
                idb--;
                deq2.push_back(a[idb]);
                idb--;
                c+=2;
            }
        }
        else
        {
            if (c==n-1)
            {
                if (abs(deq2[0]-a[ids])>=abs(deq2[deq2.size()-1]-a[ids])) deq2.push_front(a[ids]);
                else deq2.push_back(a[ids]);
                c++;
                ids++;
            }
            else
            {
                deq2.push_front(a[ids]);
                ids++;
                deq2.push_back(a[ids]);
                ids++;
                c+=2;
            }
        }
    }
    for (int i=0; i<n-1; i++) ans2+=abs(deq2[i+1]-deq2[i]);
    cout<<max(ans1, ans2);
    return 0;
}
