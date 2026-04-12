#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define MAX 1e16

using namespace std;

int main(){
    lli X,Y,Z,i,j,k,ans;
    ans = 0;

    cin>>X>>Y>>Z;


    i = Z;

    while(i<=(X-Y-Z)){
        ans++;
        i += Y+Z;
    }

    cout<<ans<<endl;
}

