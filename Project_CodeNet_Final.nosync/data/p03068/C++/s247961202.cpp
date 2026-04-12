#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;

    string ans = "";
    char temp = s[k-1];

    for(int i =0 ; i<s.size();i++)
    {
        if(s[i]==temp)
            ans = ans + temp;
        else
        {
                ans = ans + "*";
        }
        
    }
    cout<<ans;
}