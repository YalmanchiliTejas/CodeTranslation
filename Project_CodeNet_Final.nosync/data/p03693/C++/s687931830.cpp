#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((b*10+c)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}