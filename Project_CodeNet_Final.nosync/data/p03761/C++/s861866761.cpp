#include <bits/stdc++.h>

using namespace std;
string s[100];
int n;
map<char,int>q;
string s1;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(char i='a'; i<='z'; i++)
    {
        int flag=0;
        for(int j=0; j<n; j++)
        {
            if(s[j].find(i)==-1)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            int minn=100;
           // cout<<i<<endl;
            for(int j=0; j<n; j++)
            {
                int cnt=0;
                for(int z=0;z<s[j].size();z++)
                {
                    if(s[j][z]==i)
                    {
                        cnt++;
                    }
                }
                minn=min(minn,cnt);
            }
            for(int j=0;j<minn;j++)
            {
                s1+=i;
            }
        }
    }
    cout<<s1<<endl;
    return 0;
}
