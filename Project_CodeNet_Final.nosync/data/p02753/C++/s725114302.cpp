#include <bits/stdc++.h>
#define REPi(n) for(int i=0;i<n;i++)
#define REPj(n) for(int j=0;j<n;j++)

using namespace std;

int main(){
    string n,ans;
    cin >> n ;
    ans="Yes";
    if(n=="AAA"||n=="BBB"){
        ans="No";
    }

    
    cout << ans << endl;
    return 0;
}