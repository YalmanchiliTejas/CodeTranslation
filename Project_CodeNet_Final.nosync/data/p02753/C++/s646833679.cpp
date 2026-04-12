#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, c=0;
    char s[3];
    cin>> s;
    for(i=0; i<2; i++)
    {
        if(s[i]!= s[i+1])
        {
            c=1;;
            break;
        }
    }
    if(c==0)
        cout<<"No"<< endl;
    else if(c==1)
        cout<<"Yes"<< endl;
    return 0;
}
