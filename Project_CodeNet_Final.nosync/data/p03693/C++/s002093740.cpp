#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int a,b,c;
    cin >> a >>b >>c;

    if((a*100+b*10+c)%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}