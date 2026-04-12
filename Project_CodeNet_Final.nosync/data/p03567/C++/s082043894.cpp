#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct cmp1
{
    bool operator () (int &a, int &b)
    {
        return a > b ;
    }
};
int main()
{
    char a[10];
    cin>>a;
    for(int i=0;i<sizeof(a);i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
