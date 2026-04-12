#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int f1=0,f2=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A')f1=1;
        else f2=1;
    }
    if(f1+f2==2){
        puts("Yes");
    }
    else puts("No");
    return 0;
}
