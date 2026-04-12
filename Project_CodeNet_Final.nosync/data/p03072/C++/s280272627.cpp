#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,max=-2590,c=0,z;
    cin>>n;
    for(i=1;i<=n;++i){

        cin>>z;

        if(z>=max){

            max=z;
            ++c;

        }

    }
    cout<<c<<endl;

    return 0;


}
