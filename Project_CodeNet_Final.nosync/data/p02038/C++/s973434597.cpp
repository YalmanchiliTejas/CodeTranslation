#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t,i,ar[200000],it1,it2,z;
    char c,p;
    
    cin>>t;
    for (i=0;i<t;++i){
 
        cin>>c;
        z=(int)c;
        ar[i]=z;
 
    }
    for (i=0;i<t-1;++i){
 
        it1=ar[i];
        it2=ar[i+1];
        if (it1 == 84  &&  it2 == 84)ar[i+1]=84;
        else if (it1 == 84  &&  it2 == 70)ar[i+1]=70;
        else if (it1 == 70  &&  it2 == 84)ar[i+1]=84;
        else if (it1 == 70  &&  it2 == 70)ar[i+1]=84;
 
 
    }
    printf ("%c\n",ar[t-1]);
 
    return 0;
}
