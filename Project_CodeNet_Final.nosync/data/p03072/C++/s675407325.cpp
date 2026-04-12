#include<iostream>
#include<cmath>

using namespace std;

int main(){
        int ma =0;
        int t;cin>>t;
        int ans =0;
        for(int i=0;i<t;i++){
                int tmp;cin>>tmp;
                if(ma <= tmp) ans ++;
                ma = max(ma,tmp);
        }
        cout<<ans<<endl;
        return 0;
}
