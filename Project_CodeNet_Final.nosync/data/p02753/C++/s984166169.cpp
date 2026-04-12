#include <bits/stdc++.h>

using namespace std;

int main(){
    char a[3];
    cin>>a[0]>>a[1]>>a[2];

    if(a[0]!=a[1] || a[0]!=a[2] || a[1]!=a[2])
      cout<<"Yes";
    else
      cout<<"No";
}
