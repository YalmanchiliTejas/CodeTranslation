#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss,s;
    while(cin>>ss)
    {
        s="AC";
        if(ss.find(s)!=std::string::npos)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
