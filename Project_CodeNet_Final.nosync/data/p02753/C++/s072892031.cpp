#include<bits/stdc++.h>
using namespace std;
main()
{
char S[3];
int i,a=0,b=0;
cin>>S;
for(i=0;i<3;i++)
{
 if(S[i]=='A')
 {
    a++;
 }

 else if(S[i]=='B')
 {
    b++;
 }

}
if(a==2 || b==2)
{
    cout<<"Yes";
}
else
{
    cout<<"No";
}
}
