#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int binarysearch(vector<int>& v, int start,int end,int target)
{
    if(start==end)
    {
        return start;
    }
    else
    {
        int mid=(start+end)/2;
        if(v[mid]<target)
        {
            return binarysearch(v,start,mid,target);
        }
        else
        {
            return binarysearch(v,mid+1,end,target);
        }
    }
}

int main()
{
    int n;
    int s;
    int target;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> c;
    c.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        s=c.size();
        if(c[s-1]>=a[i])
        {
            c.push_back(a[i]);
        }
        else
        {
            target=binarysearch(c,0,s-1,a[i]);
            c[target]=a[i];
        }
        
    }
    cout<<c.size()<<endl;
}
