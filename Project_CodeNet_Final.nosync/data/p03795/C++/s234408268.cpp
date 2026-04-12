#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    if(n<15)
        cout<<(n*800);
    else if(n>=15){
       cout<<(n*800)-(n/15*200);
    }

return 0;
}




