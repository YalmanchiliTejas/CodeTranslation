#include<bits/stdc++.h>

using namespace std;
map<int,  map<char, int> > q;
int main()
{
    string s, su;
    int n, i, len=59, j, cnt=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        for(j=0;j<s.size();j++) q[i][s[j]]++;
        if(s.size()<len)
        {
            su=s;
            len=su.size();
        }
    }
    sort(su.begin(), su.end());
    for(i=0;i<len;i++)
    {
        for(j=0;j<n;j++)
        {
            if(q[j][su[i]]) q[j][su[i]]-- ;
            else break;
        }
        if(j==n) printf("%c",su[i]);
    }
    cout<<endl;
}
