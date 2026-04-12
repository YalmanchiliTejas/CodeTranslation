#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n==0)break;
        int ans=0;int b[n];
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        sort(b,b+n);
        for(int i=1;i<n-1;i++)ans+=b[i];
        cout << ans/(n-2) << endl;
    }
}
