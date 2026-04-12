#include<bits/stdc++.h>
using namespace std;
int n;

int main()
{
    while(cin>>n)
    {
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(s.empty()||num>=s.top()) s.push(num);
        }
        cout<<s.size()<<"\n";
    }


}
