#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>p;
int main ()
{
    int n;
    cin>>n;
    vector <int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i],a[i]*=-1;//颠倒顺序，往前找大的值

    for(int i=0;i<n;i++)
    {
        int tmp=upper_bound(p.begin(),p.end(),a[i])-p.begin();
        if(tmp==p.size())//全都比其小
        p.push_back(a[i]);//
        else
        p[tmp]=a[i];
    }
    cout<<p.size();

    return 0;
}
