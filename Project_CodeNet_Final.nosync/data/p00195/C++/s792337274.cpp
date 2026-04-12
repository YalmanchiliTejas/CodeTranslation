#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int a,b;
main()
{
    while(cin>>a>>b,a+b)
    {
        pair<int,char>p[5];
        p[0].first=a+b;
        for(int i=0;i<5;i++)p[i].second='A'+i;
        for(int i=1;i<5;i++)
        {
            cin>>a>>b;
            p[i].first=a+b;
        }
        sort(p,p+5);
        cout<<p[4].second<<" "<<p[4].first<<endl;
    }
}
