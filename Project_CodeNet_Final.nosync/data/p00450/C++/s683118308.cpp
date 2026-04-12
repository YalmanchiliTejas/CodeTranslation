#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
int main(void){

    int n;
    while(cin>>n,n){

        int a[100050] ={};
        int t = 0;
        int s = 0;
        cin>>s;
        a[0] = 1;
        t++;
        for(int i = 1;i < n;i++){
            int x;
            cin>>x;
            if(i%2 == 1){
                if((t+s)%2 == x){
                    if(t>1){
                        a[t-2] += a[t-1]+1;
                        a[t-1] = 0;
                        t--;
                    }
                    else{
                        a[t-1]++;
                        s = 1 - s;
                    }
                }
                else{
                    a[t-1]++;
                }
            }
            else{
                if((t+s)%2 == x){
                    a[t]++;
                    t++;
                }
                else{
                    a[t-1]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < t;i++){
            if(i%2 == s){
                ans += a[i];
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}