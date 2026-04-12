#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef int long long ll;



int main() {
    while(true) {
        int n, l, r;
        cin>>n>>l>>r;
        if(n+l+r==0)break;
        vector<int> a(n);
        rep(i,n){
            cin>>a[i];
        }
        int ans=0;
        for(int ye=l;ye<=r;ye++){
            bool t1=true;
            rep(i,n){
                if(ye%a[i]==0){
                    if((i+1)%2){ans++;}
                    t1=false;
                    break;
                }
            }
            if(t1){
                if(n%2==0){
                    ans++;
                }
            }

        }
        cout<<ans<<endl;
    }


    return 0;
}

