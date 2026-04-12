#include <bits/stdc++.h>
using namespace std;
#define data_type long long

int main()
{
    string str;
    char ch='a';
    cin>>str;
    for(auto i:str)
        {
            if((i=='A' && ch=='B' )||(i=='B' && ch=='A'))
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
ch=i;

        }

    cout<<"No"<<endl;
    return 0;
}

