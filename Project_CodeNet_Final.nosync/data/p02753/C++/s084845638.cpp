#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    int j,i,count1=0;
    for(i=0;i<3;i++)
        cin>>S[i];
        for(i=0;i<3;i++)
        {
            for(j=1+i;j<3;j++)
        {
            if(S[i]==S[j])
                count1++;
        }
        }
        if(count1<3)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
}
