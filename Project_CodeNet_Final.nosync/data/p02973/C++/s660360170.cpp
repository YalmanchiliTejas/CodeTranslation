#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
vector<int> A;
int main()
{
    int n;
    while(cin>>n)
    {
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            int s=A.size();
            if(!s||x<=A[s-1])
                A.push_back(x);
            else
            {
                for(int k=0;k<s;k++)
                    if(x>A[k])
                    {
                        A[k]=x;
                        break;
                    }
            }
        }
        cout<<A.size()<<endl;
    }
}