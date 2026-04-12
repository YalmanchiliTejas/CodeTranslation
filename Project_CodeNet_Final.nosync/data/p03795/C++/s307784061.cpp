#include <iostream>
#include<string>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=800*n-(n/15)*200;
    cout<<ans;

    return 0;
}