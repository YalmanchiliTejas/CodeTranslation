#include<bits/stdc++.h>

using namespace std;

int main() {

    int a,b,c;
    cin>>a>>b>>c;
    int n=a*100+b*10+c;
    if(n%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}
