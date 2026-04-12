#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
    string str;
    cin>>str;
    int n = str.length(),a=0,b=0;
    for(int i=0;i<n;i++){
        if(str[i] == 'A')a++;
        else b++;
    }
    if(a!=0 && b!=0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
