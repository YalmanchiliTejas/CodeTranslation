#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j=0,k=0;
    string s;
    cin>>s;
    for(i=0;i<3;i++)
    {
        if(s[i]=='B')
            j++;
        else
            k++;
    }
    if(j>2||k>2)
      cout<<"No";
    else
        cout<<"Yes";

}
