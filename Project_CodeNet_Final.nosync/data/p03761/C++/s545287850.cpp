#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,string>m;
void lcs(string&x,string&y)
{
    pair<int,int>temp;
    pair<int,int>temp1;
    pair<int,int>temp2;
    string z="";
    temp={0,0};
    m[temp]=z;
    for(int i=0;i<x.length();i++)
    {
        for(int j=0;j<y.length();j++)
        {
            if(x[i]==y[j])
            {
                m[make_pair(i+1,j+1)]=m[make_pair(i,j)]+x[i];
            }
            else
            {
                temp1={i+1,j};
                temp2={i,j+1};
                temp={i+1,j+1};
                if(m[temp1].length()<m[temp2].length())
                {
                    m[temp]=m[temp2];
                }
                else if(m[temp1].length()>m[temp2].length())
                {
                    m[temp]=m[temp1];
                }
                else
                {
                    if(m[temp1]<m[temp2])
                    {
                        m[temp]=m[temp1];
                    }
                    else
                    {
                        m[temp]=m[temp2];
                    }
                }
            }
        }
    }
    x= m[make_pair(x.length(),y.length())];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string x;
    string y;
    int n;
    cin>>n;
    cin>>x;
    sort(x.begin(),x.end());
    for(int i=1;i<n;i++)
    {
        cin>>y;
        sort(y.begin(),y.end());
        lcs(x,y);
    }
    cout << x<<endl;
    return 0;
}
