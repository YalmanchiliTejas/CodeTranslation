#include <bits/stdc++.h>

using namespace std;
 
#define MD 1000000007
typedef long long int ll;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=a*100+b*10+c;
    if(ans%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}