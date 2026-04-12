#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main ()
{
    int n;
    cin>>n;
    int a;
    vector<int>b;
    while(n--)
    {
        cin>>a;
        a*=-1;
        int it=upper_bound(b.begin(),b.end(),a)-b.begin();
        if(it==b.size())
        {
            b.push_back(a);
        }
        else
            b[it]=a;

    }
    cout<<b.size()<<endl;
    return 0;
}
