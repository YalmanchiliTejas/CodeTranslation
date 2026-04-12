#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a[12];
    for(int i=0;i<12;i++) cin>>a[i];
    sort(a,a+12);
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&
       a[4]==a[5]&&a[5]==a[6]&&a[6]==a[7]&&
       a[8]==a[9]&&a[9]==a[10]&&a[10]==a[11]) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}