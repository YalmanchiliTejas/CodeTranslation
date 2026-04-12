#include <iostream>

using namespace std;

int main(){
        int n,ans=1;
        int h[25];
        cin>>n;

        for(int i=0; i<n; i++){
                cin>>h[i];
        }

        for(int i=1; i<n; i++){
                for(int j=0;j<i;j++){
                        if(h[j]>h[i]) break;
                        if(j==i-1) ans++;
                }
        }

        cout<<ans<<endl;
        return 0;
}
