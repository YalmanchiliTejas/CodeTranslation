#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,t,e;
    while(cin >> n >> t >> e){
        bool f = false;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(!f){
                for(int j=a;j<=t+e;j+=a){
                    if(j >= t - e && j <= t + e){
                        f = true;
                        break;
                    }
                }
                if(f) cout << i+1 << endl;
            }
        }
        if(!f) cout << -1 << endl;
    }
}