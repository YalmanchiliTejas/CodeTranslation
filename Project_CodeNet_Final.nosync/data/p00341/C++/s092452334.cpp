#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> a;
    int b=0;
    for(int i=0;i<12;i++)
    {
        cin>>b;
        a.push_back(b);
        b=0;
    }
    sort(a.begin(),a.end());
    
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==a[7]&&a[8]==a[9]&&a[9]==a[10]&&a[10]==a[11])
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    
    return 0;
}
