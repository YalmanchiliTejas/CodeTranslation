#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[25];

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ara[i];

    int ck=0,cnt=0;

    for(int i=0;i<n;i++){
        if(ck<=ara[i]){
            cnt++;
            ck=ara[i];
        }
    }

    cout <<cnt<<endl;

    return 0;
}
