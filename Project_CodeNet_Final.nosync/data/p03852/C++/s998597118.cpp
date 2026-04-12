#include<bits/stdc++.h>
using namespace std;
char a[10]={'g','a','e','i','o','u'};
char c;
int main()
{
    c=getchar();
    for(int i=1;i<=5;i++)
    {
        if(c==a[i])
        {
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
    return 0;
}