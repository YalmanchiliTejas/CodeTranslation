// Last Update:2017-11-29 22:27:04
// author:sjy
#include<bits/stdc++.h>
using namespace std;
typedef  long long LL;
string str1,str2;
int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cin>>str1>>str2;
        if(str1 + str2 > str2 + str1)
            swap(str1,str2);
        int l1 = str1.length();
        int l2 = str2.length();
        int id = 0;
        for(int i = 0;i*l1 <= n;i++)
        {
            int c = (n-l1*i);
            if(c%l2 == 0)
            {
                id = i;
            }
        }
        string ask;
        for(int i = 0;i < id;i++)
            ask+=str1;
        for(int i = 0;i < (n-id*l1)/l2;i++)
            ask+=str2;
        cout<<ask<<endl;
        ask.clear();
    }
    return 0;
}
